//Link: https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tn = -1, tn1 = 0, tn2 = 0;
        for(auto x: nums) {
            int cwtn = tn & x;
            int cwtn1 = tn1 & x;
            int cwtn2 = tn2 & x;
            
            tn &= ~cwtn;
            tn1 |= cwtn;
            
            tn1 &= ~cwtn1;
            tn2 |= cwtn1;
            
            tn2 &= ~cwtn2;
            tn |= cwtn2;
        } 
        
        return tn1;
    }
};