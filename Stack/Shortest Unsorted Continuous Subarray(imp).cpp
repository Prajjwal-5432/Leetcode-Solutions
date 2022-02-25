//Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end())) return 0;
        
        vector<int> v;
        
        int l = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            bool flag = 0;
            while(!v.empty() and nums[i] < nums[v.back()]) {
                flag = 1;
                v.pop_back();
            }
            if(flag and l > v.size()) l = v.size();
            v.push_back(i);
        }
        
        v.clear();
        
        int r = nums.size();
        for(int i = nums.size() - 1; i >= 0; --i) {
            bool flag = 0;
            while(!v.empty() and nums[i] > nums[v.back()]) {
                flag = 1;
                v.pop_back();
            }
            if(flag and r > v.size()) r = v.size();
            v.push_back(i);
        }
        
        r = nums.size() - r;
        l++;
        
        return r - l + 1;
    }
};