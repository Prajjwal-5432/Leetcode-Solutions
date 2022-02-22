//Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int op = 0, cnt = 0;
        
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') op++;
            else {
                if(op == 0) cnt++;
                else op--;
            }
        }
        
        return cnt + op;
    }
};