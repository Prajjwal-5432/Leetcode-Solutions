//Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/
//refer: https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/593403/Bit-masks-no-loops

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long diff = right - left;
        unsigned mask = -1;
        
        while(diff) {
            diff >>= 1;
            mask <<= 1;
        }
        
        return mask & left & right;
    }
};