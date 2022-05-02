//Link: https://leetcode.com/problems/largest-sum-of-averages/

class Solution {
public:
    #define max(a, b)   a > b ? a : b
    
    const static int nx = 110;
    long double dp[nx][nx];
    vector<int> nums;
    int n;
    
    double func(int ind, int k) {
        if(ind == n) {
            if(k == 0) return 0;
            return INT_MIN / 2;
        }
        
        if(dp[ind][k] != -1) return dp[ind][k];
        
        long sum = 0;
        long double ans = INT_MIN / 2;
        
        if(k) {
            for(int i = ind; i < n; ++i) {
                sum += nums[i];
                ans = max(ans, sum / double(i - ind + 1) + func(i + 1, k - 1));
            }
        } 
        
        return dp[ind][k] = ans;
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        this->nums = nums;
        for(int i = 0; i < nx; ++i) for(int j = 0; j < nx; ++j) dp[i][j] = -1;
        
        return func(0, k);
    }
};