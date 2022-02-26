//Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
//After popping operations equal no's of closing braces will be followed by equal no's of opening braces

class Solution {
public:
    int minSwaps(string s) {
        int close = 0, open = 0;
        for(auto x: s) {
            if(x == '[') open++;
            else open ? open-- : close++;
        }
        
        open += close;
        
        return open / 4 + (open % 4 ? 1 : 0);
    }
};