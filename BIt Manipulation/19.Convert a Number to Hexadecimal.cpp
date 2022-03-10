//Link: https://leetcode.com/problems/convert-a-number-to-hexadecimal/

class Solution {
public:
    string toHex(int n) {
        vector<char> v;
        for(char x = '0'; x <= '9'; ++x) v.push_back(x);
        for(char x = 'a'; x <= 'f'; ++x) v.push_back(x);
        
        string s;
        if(n == 0) return "0";
        
        if(n >= 0) {
            for(; n; n /= 16) s += v[n % 16];
        } else {
            uint32_t num = n;
            for(; num; num /= 16) s += v[num % 16];
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};