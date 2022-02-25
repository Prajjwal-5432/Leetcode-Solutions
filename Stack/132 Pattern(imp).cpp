//Link: https://leetcode.com/problems/132-pattern/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int prev = INT_MIN;
        vector<int> v;
        
        for(int i = nums.size() - 1; i >= 0; --i) {
            if(nums[i] < prev) return true;
            else while(!v.empty() and nums[i] > v.back()) {
                prev = v.back(), v.pop_back();
            }
            v.push_back(nums[i]);
        }
        
        return false;
    }
};