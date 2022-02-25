//Link: https://leetcode.com/problems/basic-calculator-ii/
class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        
        if(!len) return 0;
        
        int cn = 0, ln = 0, res = 0;
        char sign = '+';
        
        for(int i = 0; i < len; ++i) {
            if(isdigit(s[i])) {
                cn = cn * 10 + (s[i] - '0');
            }
            if(!isdigit(s[i]) and !iswspace(s[i]) or i == len - 1) {
                if(sign == '+' or sign == '-') {
                    res += ln;
                    ln = (sign == '+' ? cn : -cn);
                } else if(sign == '*') {
                    ln = ln * cn;
                } else {
                    ln = ln / cn;
                }
                cn = 0;
                sign = s[i];
            }
        }
        
        res += ln;
        
        return res;
    }
};