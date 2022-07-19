//Link: https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    int dp[101][101];
    int n, m;
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if(i >= grid.size()) return j;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = -1;
        if(grid[i][j] == 1 and j + 1 < m and grid[i][j + 1] == 1)
            ans = dfs(i + 1, j + 1, grid);
        if(grid[i][j] == -1 and j - 1 >= 0 and grid[i][j - 1] == -1)
            ans = dfs(i + 1, j - 1, grid);
        
        return dp[i][j] = ans;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);
        
        vector<int> res(m, -1);
        for(int j = 0; j < m; ++j) res[j] = dfs(0, j, grid);
        
        return res;
    }
};