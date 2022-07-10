//Link: https://leetcode.com/problems/stone-game-iv/

int dp[100012][2];

class Solution {
public:
    int dfs(int n, int chance) {
        if(n == 0) return 1;
        if(dp[n][chance] != -1) return dp[n][chance];
        
        int ans = 0;
        for(int i = 1; i * i <= n; ++i) {
            ans |= dfs(n - i * i, chance ^ 1);
        }
        
        return dp[n][chance] = !ans;
    }
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof dp);
        return !dfs(n, 1);
    }
};