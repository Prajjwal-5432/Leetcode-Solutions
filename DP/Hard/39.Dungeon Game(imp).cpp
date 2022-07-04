//Link: https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int dp[222][222];
    vector<vector<int>> d;
    int n, m;
    
    int dfs(int i, int j) {
        if(i == n - 1 and j == m - 1) return d[i][j] >= 0 ? 1 : -d[i][j] + 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        int req = INT_MAX / 2;
        if(i + 1 < n) 
            req = min(req, dfs(i + 1, j));
        if(j + 1 < m)
            req = min(req, dfs(i, j + 1));
        
        if(req <= d[i][j])
            return dp[i][j] = 1;
        
        return dp[i][j] = req - d[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof dp);    
        this->d = dungeon;
        this->n = d.size();
        this->m = d[0].size();
        
        return dfs(0, 0);
    }
};