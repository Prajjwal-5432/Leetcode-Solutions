//Link: https://leetcode.com/problems/trapping-rain-water-ii/

class Solution {
public:
    int trapRainWater(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        for(int i = 0; i < n; ++i) {
            pq.push({a[i][0], i, 0});
            pq.push({a[i][m - 1], i, m - 1});
            vis[i][0] = vis[i][m - 1] = 1;
        }
        for(int j = 1; j < m - 1; ++j) {
            pq.push({a[0][j], 0, j});
            pq.push({a[n - 1][j], n - 1, j});
            vis[0][j] = vis[n - 1][j] = 1;
        }
        
        int water = 0;
        while(!pq.empty()) {
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            
            auto [val, i, j] = pq.top();
            pq.pop();
            
            for(int t = 0; t < 4; ++t) {
                int x = i + dx[t];
                int y = j + dy[t];
                
                if(x >= 0 and y >= 0 and x < n and y < m and !vis[x][y]) {
                    vis[x][y] = 1;
                    pq.push({max(val, a[x][y]), x, y});
                    water += max(0, val - a[x][y]);
                }
            }
        }
        return water;
    }
};