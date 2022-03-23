//Link: https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<bool>> vis;
    int sr, sc, er, ec, n, m, cells, cnt;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    void traverse(int r, int c, int tot) {
        if(r == er and c == ec) {
            if(cells == tot) cnt++;
            return;
        }
        for(int i = 0; i < 4; ++i) {
            int x = r + dx[i];
            int y = c + dy[i];
            
            if(x >= 0 and y >= 0 and x < n and y < m and !vis[x][y] and grid[x][y] != -1) {
                vis[x][y] = 1;
                traverse(x, y, tot + 1);
                vis[x][y] = 0;
            }
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size(), m = grid[0].size();
        
        vis.resize(n, vector<bool> (m, 0));
        
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 1) sr = i, sc = j;
            if(grid[i][j] == 2) er = i, ec = j;
            cells += (grid[i][j] == -1);
        }
        
        cells = n * m - cells;
        vis[sr][sc] = 1;
        traverse(sr, sc, 1);
        
        return cnt;
    }
};