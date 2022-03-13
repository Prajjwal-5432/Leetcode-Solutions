//Link: https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int x, int y) {
        while(y != 0) {
            
            // carry should be unsigned to
            // deal with -ve numbers
            // carry now contains common
            //set bits of x and y

            unsigned carry = x & y;
            x ^= y;
            y = carry << 1;
        }
        
        return x;
    }
};