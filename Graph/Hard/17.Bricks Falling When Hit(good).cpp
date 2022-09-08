//Link: https://leetcode.com/problems/bricks-falling-when-hit/

class Solution {
public:
    vector<int> par, lev;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int fset(int v) {
        return v == par[v] ? v : par[v] = fset(par[v]);
    }
    void uset(int u, int v) {
        u = fset(u), v = fset(v);
        if(u != v) {
            if(lev[u] < lev[v]) swap(u, v);
            par[v] = u;
            lev[u] += lev[v];
        }
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> orig = grid;
        
        par.resize(n * m + 1);
        lev.resize(n * m + 1, 1);
        iota(par.begin(), par.end(), 0);
        
        for(auto x: hits) grid[x[0]][x[1]] = 0;
        
        for(int j = 0; j < m; ++j) if(grid[0][j] == 1) uset(j, n * m);
        
        for(int i = 1; i < n; ++i) for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 0) continue;
            for(int t = 0; t < 4; ++t) {
                int x = i + dx[t];
                int y = j + dy[t];
                if(x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 1) {
                    uset(i * m + j, x * m + y);
                }
            }
        }
        int q = hits.size();
        vector<int> res(q);
        for(int i = q - 1; ~i; --i) {
            int x = hits[i][0], y = hits[i][1];
            int prev = lev[fset(n * m)];
            
            if(orig[x][y] == 0) continue;
            
            grid[x][y] = 1;
            if(x == 0) uset(x * m + y, n * m);
            for(int t = 0; t < 4; ++t) {
                int nx = x + dx[t];
                int ny = y + dy[t];
                if(nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny] == 1) {
                    uset(x * m + y, nx * m + ny);
                }
            }
            
            int cur = lev[fset(n * m)];
            res[i] = max(cur - prev - 1, 0);
        }
        return res;
    }
};