//Link: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i = n - 1; ~i; --i) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j) {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < word1.length(); ++i) for(int j = 0; j < word2.length(); ++j) {
            if(word1[i] == word2[j])
                ans = max(ans, 2 + dp[i + 1][word1.length() + j - 1]);
        }
        
        return ans;
    }
};