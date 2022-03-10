//Link: https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0;
        for(int i = 0; i < 32; ++i, n >>= 1) {
            num <<= 1;
            num |= (n & 1);
        }
        
        return num;
    }
};