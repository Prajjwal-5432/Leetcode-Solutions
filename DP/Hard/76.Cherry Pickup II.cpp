//Link: https://leetcode.com/problems/cherry-pickup-ii/

int dp[77][77][77];

class Solution {
public:
    int n, m;
    bool good(int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    int dfs(int r1, int c1, int c2, vector<vector<int>>& grid) {
        if(r1 == grid.size()) return 0;
        if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        
        int dx[] = {1, 1, 1};
        int dy[] = {-1, 0, 1};
        
        int ans = 0;
        for(int t = 0; t < 3; ++t) {
            int x = r1 + dx[t];
            int y = c1 + dy[t];
            for(int u = 0; u < 3; ++u) {
                int yy = c2 + dy[u];
                if(good(x, y) and good(x, yy) and y != yy) {
                    ans = max(ans, dfs(x, y, yy, grid) + grid[x][y] + grid[x][yy]);
                }
            }
        }
        return dp[r1][c1][c2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        n = grid.size(), m = grid[0].size();
        return dfs(0, 0, m - 1, grid) + grid[0][0] + grid[0][m - 1];
    }
};