//Link: https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
// Similar as 2d prefix sum

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        
        priority_queue<int, vector<int>, greater<>> pq;
        
        for(int j = 1; j < m; ++j) matrix[0][j] ^= matrix[0][j - 1];
        for(int i = 1; i < n; ++i) matrix[i][0] ^= matrix[i - 1][0];
        
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
            }
        }
        
        for(auto x: matrix) for(auto y : x) {
            if(pq.size() < k) pq.push(y);
            else if(y > pq.top()) {
                pq.pop();
                pq.push(y);
            }
        }
        
        return pq.top();
    }
};