//Link: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
//treat every )) as a single ] problem becomes easy
class Solution {
public:
    int minInsertions(string s) {
        s += ".";
        
        int left = 0, count = 0;
        
        for(int i = 0; i < s.length() - 1; ++i) {
            if(s[i] == '(') left++;
            else {
                string t = s.substr(i, 2);
                if(t == "))" and left) left--, i++;
                else if(t == ")(" and left) left--, count++;
                else if(t == ")." and left) left--, count++;
                else if(t == "))") count++, i++;
                else if(t == ")(") count += 2;
                else if(t == ").") count += 2;
            }
        }
        
        return count + left * 2;
    }
};