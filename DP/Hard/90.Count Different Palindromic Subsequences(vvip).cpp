//Link: https://leetcode.com/problems/count-different-palindromic-subsequences/
//Refer pepcoding video

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        vector<int> next(n), prev(n);
        vector<int> ind(26, -1);
        
        for(int i = 0; i < n; ++i) {
            prev[i] = ind[s[i] - 'a'];
            ind[s[i] - 'a'] = i;
        }
        ind.clear();
        ind.resize(26, -1);
        for(int i = n - 1; ~i; --i) {
            next[i] = ind[s[i] - 'a'];
            ind[s[i] - 'a'] = i;
        }
        
        vector<vector<long long>> dp(n, vector<long long> (n, 0));
        long long mod = 1e9 + 7;
        
        for(int gap = 0; gap < n; ++gap) {
            for(int i = 0, j = gap; j < n; ++i, ++j) {
                if(gap < 2) dp[i][j] = gap + 1;
                else {
                    if(s[i] != s[j]) dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + mod) % mod;
                    else {
                        int nxt = next[i];
                        int pre = prev[j];
                        if(nxt > pre)
                            dp[i][j] = (2 * dp[i + 1][j - 1] + 2 + mod) % mod;
                        else if(nxt == pre)
                            dp[i][j] = (2 * dp[i + 1][j - 1] + 1 + mod) % mod;
                        else
                            dp[i][j] = (2 * dp[i + 1][j - 1] - dp[nxt + 1][pre - 1] + mod) % mod;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};