//Link: https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int val = 0;
        for(int i = 0; i < nums.size(); ++i) {
            val ^= nums[i] ^ (i + 1);
        }
        
        return val;
    }
};