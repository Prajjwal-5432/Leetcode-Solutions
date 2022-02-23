//Link: https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v, ans(n, -1);
        
        for(int i = 0; i < n; ++i) {
            while(!v.empty() and nums[i] > nums[v.back()]) {
                ans[v.back()] = nums[i];
                v.pop_back();
            }
            v.push_back(i);
        }
        
        for(int i = 0; i < n and !v.empty(); ++i) {
            while(!v.empty() and nums[i] > nums[v.back()]) {
                ans[v.back()] = nums[i];
                v.pop_back();
            }       
        }
        
        return ans;
    }
};