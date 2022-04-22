//Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        multiset<pair<int, int>> st;
        
        for(int i = 0; i < nums.size(); ++i) {
            reverse(nums[i].begin(), nums[i].end());
            st.insert({nums[i].back(), i});
        }
        
        int len = INT_MAX, r, l;
        
        while(true) {
            int l_ = st.begin()->first;
            int r_ = st.rbegin()->first;
            
            if(r_ - l_ < len) {
                len = r_ - l_;
                r = r_, l = l_;
            }
            
            int ind = st.begin()->second;
            int val = st.begin()->first;
            
            nums[ind].pop_back();
            if(nums[ind].empty()) break;
            
            st.erase(st.find({val, ind}));
            st.insert({nums[ind].back(), ind});
        }
        
        return {l, r};
    }
};