//Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        queue<array<int, 4>> q;
        int vis[n][m][k + 1];
        memset(vis, 0, sizeof vis);
        
        vis[0][0][k] = 1;
        q.push({0, 0, k, 0});
        
        while(!q.empty()) {
            auto [i, j, curk, dis] = q.front();
            q.pop();
            
            if(i == n - 1 and j == m - 1) return dis;
            
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            
            for(int t = 0; t < 4; ++t) {
                int x = i + dx[t];
                int y = j + dy[t];
                if(x >= 0 and y >= 0 and x < n and y < m) {
                    int nk = curk - grid[x][y];
                    if(nk >= 0 and !vis[x][y][nk]) {
                        q.push({x, y, nk, dis + 1});
                        vis[x][y][nk] = 1;
                    }
                }
            }
        }
        
        return -1;
    }
};