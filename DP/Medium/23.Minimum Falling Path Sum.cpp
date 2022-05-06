//Link: https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int dx[3] = {-1, -1, -1};
    int dy[3] = {-1, 0, 1};
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int mn = INT_MAX / 2;
                for(int d = 0; d < 3; ++d) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    
                    if(min(x, y) >= 0 and max(x, y) < n) {
                        mn = min(mn, matrix[i][j] + matrix[x][y]);
                    }
                }
                
                matrix[i][j] = mn;
            }
        }
        
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};