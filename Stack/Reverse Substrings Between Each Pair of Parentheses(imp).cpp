//Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> v, pair(s.length());
        
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') v.push_back(i);
            else if(s[i] == ')') {
                pair[i] = v.back();
                pair[v.back()] = i;
                v.pop_back();
            }
        }
        
        string res;
        for(int i = 0, d = 1; i < s.length(); i += d) {
            if(s[i] == '(' or s[i] == ')') {
                i = pair[i], d *= -1;
            } else {
                res += s[i];
            }
        }
        
        return res;
    }
};