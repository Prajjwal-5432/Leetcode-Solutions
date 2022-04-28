//Link: https://leetcode.com/problems/maximum-number-of-points-with-cost/

class Solution {
public:
    
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        
        vector<vector<long long>> dp(n, vector<long long> (m, -1));
        
        for(int i = 0; i < m; ++i)
            dp[0][i] = points[0][i];
        
        for(int i = 1; i < n; ++i) {
            vector<long long> left_dp(m, -1);
            vector<long long> right_dp(m, -1);
            
            left_dp[0] = dp[i - 1][0];
            for(int k = 1; k < m; ++k)
                left_dp[k] = max(left_dp[k - 1], dp[i - 1][k] + k);
            
            right_dp[m - 1] = dp[i - 1][m - 1] - m + 1;
            for(int k = m - 2; ~k; --k) 
                right_dp[k] = max(right_dp[k + 1], dp[i - 1][k] - k);
            
            for(int j = 0; j < m; ++j) 
                dp[i][j] = max(left_dp[j] - j, right_dp[j] + j) + points[i][j];
        }
        
        long long ans = 0;
        for(auto x: dp.back())
            ans = max(ans, x);
        
        return ans;
    }
};