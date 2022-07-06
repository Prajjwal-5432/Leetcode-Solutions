//Link: https://leetcode.com/problems/valid-permutations-for-di-sequence/
//Refer: https://leetcode.com/problems/valid-permutations-for-di-sequence/discuss/168612/Top-down-with-Memo-greater-Bottom-up-DP-greater-N3-DP-greater-N2-DP-greater-O(N)-space
class Solution {
public:
    int numPermsDISequence(string s) {
        int n = s.size(), mod = 1e9 + 7;
        vector<vector<long>> dp(n + 1, vector<long> (n + 1, 0));
        
        for(int j = 0; j <= n; ++j) dp[0][j] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= i; ++j) {
                dp[i][j] = j ? dp[i][j - 1] : 0;
                if(s[i - 1] == 'D') {
                    dp[i][j] += dp[i - 1][i - 1] - (j ? dp[i - 1][j - 1] : 0);
                } else {
                    dp[i][j] += j ? dp[i - 1][j - 1] : 0;
                }
                dp[i][j] = (dp[i][j] + mod) % mod;
            }
        }
        
        return dp[n][n];
    }
};