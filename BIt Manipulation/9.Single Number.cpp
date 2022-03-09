//Link: https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for(auto x: nums) val ^= x;
        return val;
    }
};