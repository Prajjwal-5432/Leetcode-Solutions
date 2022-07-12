//Link: https://leetcode.com/problems/strange-printer/
//Same as remove boxes though we don't need 3rd state

int dp[111][111];

class Solution {
public:
    int dfs(int i, int j, string& s) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int io = i;
        while(i + 1 <= j and s[i] == s[i + 1]) i++;
        
        int ans = 1 + dfs(i + 1, j, s);
        for(int m = i + 1; m <= j; ++m) {
            if(s[i] == s[m]) {
                ans = min(ans, dfs(i + 1, m - 1, s) + dfs(m, j, s));
            }
        }
        
        return dp[io][j] = ans;
    }
    int strangePrinter(string s) {
        memset(dp, -1, sizeof dp);
        
        return dfs(0, s.length() - 1, s);
    }
};