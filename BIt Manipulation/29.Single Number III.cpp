//Link: https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long val = 0;
        for(auto x: nums) val ^= x;
        
        val &= -val;
        
        int x = 0, y = 0;
        for(auto num: nums) {
            if((num & val) == 0) x ^= num;
            else y ^= num;
        }
        
        return {x, y};
    }
};