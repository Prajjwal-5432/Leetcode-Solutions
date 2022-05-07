//Link: https://leetcode.com/problems/longest-palindromic-subsequence/

const int nx = 1100;
int dp[nx][nx];

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.length();
        for(int i = 1; i < n + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        return dp[n][n];
    }
};