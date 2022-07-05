//Link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> st({INT_MAX});
        
        long tot = 0;
        for(auto x: arr) {
            while(st.back() <= x) {
                long bk = st.back();
                st.pop_back();
                tot += bk * min(st.back(), x);
            }
            st.push_back(x);
        }
        
        for(int i = 2; i < st.size(); ++i) {
            tot += st[i] * st[i - 1];
        }
        
        return tot;
    }
};