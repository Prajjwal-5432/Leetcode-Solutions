//Link: https://leetcode.com/problems/valid-parenthesis-string/
//Refer: https://leetcode.com/problems/valid-parenthesis-string/discuss/107570/JavaC%2B%2BPython-One-Pass-Count-the-Open-Parenthesis
class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        
        for(auto x: s) {
            if(x == '(') cmax++, cmin++;
            else if(x == ')') cmax--, cmin = max(cmin - 1, 0);
            else cmax++, cmin = max(cmin - 1, 0);
            
            if(cmax < 0) return 0;
        }
        
        return cmin == 0;
    }
};