//Link: https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1) return vector<int> ({0, 1});
        
        vector<int> v = grayCode(n - 1);
        vector<int> ans(2 * v.size());
        
        for(int i = 0; i < v.size(); ++i) {
            ans[i] = v[i];
            ans[2 * v.size() - i - 1] = v[i] | (1 << (n - 1));
        }
        
        return ans;
    }
};