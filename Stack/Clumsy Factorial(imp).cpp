//Link: https://leetcode.com/problems/clumsy-factorial/
//Refer to the question basic calculator II
//there is also an O(1) time complexity solution

class Solution {
public:
    int clumsy(int n) {
        int ln = 0, res = 0;
        vector<char> ch = {'*', '/', '+', '-'};
        char sign = '+';
            
        for(int i = 0, cn = n, j = 3; i < 2 * n - 1; ++i) {
            if(i & 1 or i == 2 * n - 2) {
                if(sign == '+' or sign == '-') {
                    res += ln;
                    ln = (sign == '+' ? cn : -cn);
                } else if(sign == '*') {
                    ln *= cn;
                } else {
                    ln /= cn;
                }
                j = (j + 1) % 4;
                sign = ch[j];
                cn--;
            }
        }
        
        return res + ln;
    }
};