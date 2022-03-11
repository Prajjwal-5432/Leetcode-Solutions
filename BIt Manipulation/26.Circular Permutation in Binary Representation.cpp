//Link: https://leetcode.com/problems/circular-permutation-in-binary-representation/

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
    vector<int> circularPermutation(int n, int start) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        vector<int> gray = grayCode(n);
        
        int ind;
        for(int i = 0; i < gray.size(); ++i) {
            if(gray[i] == start) ind = i;
        }
        
        rotate(gray.begin(), gray.begin() + ind, gray.end());

        return gray;
    }
};