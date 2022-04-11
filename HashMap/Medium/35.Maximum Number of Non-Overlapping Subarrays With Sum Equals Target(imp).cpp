//Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int sum = 0, cnt = 0, lind = -1;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(mp.count(sum - target)) {
                if(mp[sum - target] >= lind) {
                    cnt++;
                    lind = i;
                }
            }
            mp[sum] = i;
        }
        
        return cnt;
    }
};