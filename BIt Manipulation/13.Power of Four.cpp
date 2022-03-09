//Link: https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int x) {
        int mask = 0b01010101010101010101010101010101;
        return x > 0 and ((x & (x - 1)) == 0 and (x | mask) == mask);
    }
};