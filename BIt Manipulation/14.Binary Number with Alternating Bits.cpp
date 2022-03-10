//Link: https://leetcode.com/problems/binary-number-with-alternating-bits/
/*
       n =         1 0 1 0 1 0 1 0
       n >> 1      0 1 0 1 0 1 0 1
       n ^ n>>1    1 1 1 1 1 1 1 1
       n           1 1 1 1 1 1 1 1
       n + 1     1 0 0 0 0 0 0 0 0
       n & (n+1)   0 0 0 0 0 0 0 0
*/


class Solution {
public:
    bool hasAlternatingBits(long n) {
        n = n ^ (n >> 1);
        
        return (n & (n + 1)) == 0;
    }
};