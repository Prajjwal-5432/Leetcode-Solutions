//Link: https://leetcode.com/problems/valid-parenthesis-string/
//Refer: https://leetcode.com/problems/valid-parenthesis-string/discuss/107570/JavaC%2B%2BPython-One-Pass-Count-the-Open-Parenthesis
class Solution {
public:
    bool checkValidString(string s) {
        vector<int> open, star;
        
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') open.push_back(i);
            else if(s[i] == '*') star.push_back(i);
            else {
                if(!open.empty()) open.pop_back();
                else if(!star.empty()) star.pop_back();
                else return 0;
            }
        }
        
        while(!open.empty()) {
            if(!star.empty() and open.back() < star.back()) star.pop_back(), open.pop_back();
            else return 0;
        }
        
        return 1;
    }
};