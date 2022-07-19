//Link: https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        for(int i = 1; i < n + 1; ++i) {
            for(int j = 1; j < m + 1; ++j) {
                if(s1[i - 1] == s2[j - 1]) 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string res = "";
        for(int i = n, j = m; i || j;) {
            if(i > 0 and dp[i][j] == dp[i - 1][j]) res.push_back(s1[--i]);
            else if(j > 0 and dp[i][j] == dp[i][j - 1]) res.push_back(s2[--j]);
            else res.push_back(s1[--i]), --j;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};