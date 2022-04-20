//Link: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        int cnt = 0;
        for(int r1 = 0; r1 < n; ++r1) {
            int v[m];
            memset(v, 0, sizeof(v));
            for(int r2 = r1; r2 < n; ++r2) {
                for(int j = 0; j < m; ++j) {
                    v[j] += matrix[r2][j];
                }
                
                unordered_map<long, int> mp;
                mp[0] = 1;
                long pref = 0;
                
                for(int j = 0; j < m; ++j) {
                    pref += v[j];
                    cnt += mp[pref - target];
                    mp[pref] += 1;
                }
            }
        }
        
        return cnt;
    }
};