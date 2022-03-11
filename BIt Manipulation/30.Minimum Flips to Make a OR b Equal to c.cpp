//Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        
        for(int i = 0; a or b or c; a >>= 1, b >>= 1, c >>= 1) {
            int bita = a & 1, bitb = b & 1, bitc = c & 1;
            
            if(bitc == 0) flips += bita + bitb;
            else if(bita == 0 and bitb == 0) flips++;
        }
        
        return flips;
    }
};