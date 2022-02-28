//Link: https://leetcode.com/problems/count-submatrices-with-all-ones/
//Refer: https://leetcode.com/problems/count-submatrices-with-all-ones/discuss/720265/Java-Detailed-Explanation-From-O(MNM)-to-O(MN)-by-using-Stack
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        int res = 0;
        for(int row = 0; row < n; ++row) {
            vector<int> height(m, 1);
            
            for(int i = row; i < n; ++i) {
                for(int j = 0; j < m; ++j) height[j] &= mat[i][j];
                res += countMatrices(height);
            }
        }
        return res;
    }
    
    int countMatrices(vector<int> height) {
        int res = 0, len = 0;
        for(auto x: height) {
            len = (x ? len + 1 : 0);
            res += len;
        }
        
        return res;
    }
};