//Link: https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int dp[555][555];
    int dfs(int i, int j, string &s1, string &s2) {
        if(i >= s1.size()) return s2.length() - j;
        if(j >= s2.size()) return s1.length() - i;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 12345;
        if(s1[i] == s2[j])
            ans = dfs(i + 1, j + 1, s1, s2);
        else
            ans = 1 + min({dfs(i + 1, j, s1, s2), dfs(i, j + 1, s1, s2), dfs(i + 1, j + 1, s1, s2)});
        
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, word1, word2);
    }
};