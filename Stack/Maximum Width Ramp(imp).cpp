//Link: https://leetcode.com/problems/maximum-width-ramp/
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> v;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(v.empty() or nums[v.back()] > nums[i]) v.push_back(i);
        }
        
        int ramp = 0;
        
        for(int i = nums.size() - 1; i >= 0; --i) {
            while(!v.empty() and nums[i] >= nums[v.back()]) { 
                ramp = max(ramp, i - v.back());
                v.pop_back();
            }
        }
        
        return ramp;
    }
};