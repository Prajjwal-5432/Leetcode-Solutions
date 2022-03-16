//Link: https://leetcode.com/problems/score-after-flipping-matrix/
//We should turn every value of the first col 1 to get the maximum sum

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for(int j = 0; j < m; ++j) {
            for(int i = 0; i < n; ++i) {
                if(grid[i][j]) continue;
                int td1 = 0, lr1 = 0;
                for(int k = 0; k < n; ++k) td1 += grid[k][j];
                for(int k = 0; k < j + 1; ++k) lr1 += grid[i][k];
                
                if(td1 < n - td1 and j) {
                    for(int k = 0; k < n; ++k) grid[k][j] = 1 - grid[k][j];
                } else if(lr1 == 0) {
                    for(int k = 0; k < m; ++k) grid[i][k] = 1 - grid[i][k];
                }
            }
        }
        
        long sum = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j]) 
                    sum += (1 << (m - j - 1));
            }
        }
        
        return sum;
    }
};