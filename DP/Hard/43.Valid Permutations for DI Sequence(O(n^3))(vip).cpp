//Link: https://leetcode.com/problems/valid-permutations-for-di-sequence/

class Solution {
public:
    int numPermsDISequence(string s) {
        int n = s.size(), mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
        dp[0][0] = 1;
        for(int i = 1; i < n + 1; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(s[i - 1] == 'D') {
                    for(int k = j; k <= i - 1; ++k) 
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                } else {
                    for(int k = 0; k <= j - 1; ++k) 
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < n + 1; ++i) res = (res + dp[n][i]) % mod;
        
        return res;
    }
};