//Link: https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/

class Solution {
public:
    int ans;
    
    void cover(int r, int c, int k, vector<vector<bool>> &rect) {
        for(int i = 0; i < k; ++i) for(int j = 0; j < k; ++j) rect[r + i][c + j] = 1;
    }
    void uncover(int r, int c, int k, vector<vector<bool>> &rect) {
        for(int i = 0; i < k; ++i) for(int j = 0; j < k; ++j) rect[r + i][c + j] = 0;
    }
    bool isAvailable(int r, int c, int k, vector<vector<bool>> &rect) {
        bool ok = 0;
        for(int i = 0; i < k; ++i) for(int j = 0; j < k; ++j) ok |= rect[r + i][c + j];
        return !ok;
    }
    void dfs(int r, int c, vector<vector<bool>> &rect, int res) {
        if(res >= ans) return;
        
        int n = rect.size(), m = rect[0].size();
        if(r >= n) {
            ans = min(ans, res);
            return;
        }
        
        if(c >= m) {
            dfs(r + 1, 0, rect, res);
            return;
        }
        
        if(rect[r][c]) {
            dfs(r, c + 1, rect, res);
            return;
        }
        
        for(int k = min(n - r, m - c); k > 0 and isAvailable(r, c, k, rect); --k) {
            cover(r, c, k, rect);
            dfs(r, c + 1, rect, res + 1);
            uncover(r, c, k, rect);
        }
    }
    int tilingRectangle(int n, int m) {
        ans = INT_MAX;    
        vector<vector<bool>> rect(n, vector<bool> (m, 0));
        
        dfs(0, 0, rect, 0);
        
        return ans;
    }
};