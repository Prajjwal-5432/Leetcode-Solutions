//Link: https://leetcode.com/problems/find-the-most-competitive-subsequence/
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            while(!st.empty() and st.back() > nums[i] and n - i >= k - st.size() + 1) st.pop_back();
            if(st.size() == k and nums[i] >= st.back()) continue;
            st.push_back(nums[i]);
        }
        
        return st;
    }
};