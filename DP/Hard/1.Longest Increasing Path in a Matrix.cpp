//Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

const int nx = 250;
long dp[nx][nx];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    vector<vector<int>> matrix;
    int n, m;
    
    long func(int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        
        long ans = 0;
        for(int t = 0; t < 4; ++t) {
            int x = i + dx[t];
            int y = j + dy[t];
            
            if(min(x, y) >= 0 and x < n and y < m and matrix[x][y] > matrix[i][j]) {
                ans = max(ans, func(x, y));
            }
        }
        
        return dp[i][j] = ans + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof dp);  
        this->matrix = matrix;
        this->n = matrix.size();
        this->m = matrix[0].size();
        
        long best = 1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                best = max(best, func(i, j));
        
        return best;
    }
};