//Link: https://leetcode.com/problems/decoded-string-at-index/
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        for(auto x: s) len = isdigit(x) ? len * (x - '0') : len + 1;
        
        for(int i = s.length() - 1; i >= 0; --i) {
            k %= len;
            if(k == 0 and !isdigit(s[i])) return string(1, s[i]);
            if(isdigit(s[i])) len /= (s[i] - '0');
            else len--;
        }
        
        return "";
    }
};