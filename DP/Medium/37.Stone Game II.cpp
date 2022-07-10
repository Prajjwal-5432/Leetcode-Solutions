//Link: https://leetcode.com/problems/stone-game-ii/

class Solution {
public:
    int dp[100][300][2];
    int dfs(int ind, int m, int chance, vector<int> &piles) {
        if(ind >= piles.size()) return 0;
        if(dp[ind][m][chance] != -1) return dp[ind][m][chance];
        
        int ans = chance ? 0 : INT_MAX / 2;
        int sum = 0;
        for(int i = 0; i < 2 * m and i + ind < piles.size(); ++i) {
            sum  += piles[i + ind];
            if(chance) 
                ans = max(ans, sum + dfs(i + ind + 1, max(m, i + 1), chance ^ 1, piles));
            else
                ans = min(ans, dfs(i + ind + 1, max(m, i + 1), chance ^ 1, piles));
        }
        return dp[ind][m][chance] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof dp);
        return dfs(0, 1, 1, piles);
    }
};