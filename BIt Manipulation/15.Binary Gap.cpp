//Link: https://leetcode.com/problems/binary-gap/

class Solution {
public:
    int binaryGap(int n) {
        int prev = -1, mx = 0;
        
        for(int i = 1; n; n >>= 1, ++i) {
            if(n & 1) {
                if(prev != -1) mx = max(mx, abs(prev - i));
                prev = i;
            }
        }
        
        return mx;
    }
};