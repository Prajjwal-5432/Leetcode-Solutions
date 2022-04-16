//Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        unordered_map<int, int> mp;
        int n = a.size();
        
        for(int i = 0; i < n; ++i) 
            mp[a[i]] = i;
        
        int dp[n][n], res = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(a[i] - a[j] < a[j] and mp.count(a[i] - a[j])) {
                    int k = mp[a[i] - a[j]];
                    
                    dp[j][i] = dp[k][j] + 1;
                } else {
                    dp[j][i] = 2;
                }
                res = max(res, dp[j][i]);
            }
        }
        
        return res > 2 ? res : 0;
    }
};