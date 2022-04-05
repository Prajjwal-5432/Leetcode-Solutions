//Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int sub = 0, a = 0, b = 0, c = 0, l = 0;
        
        for(int i = 0; i < s.length(); ++i) {
            a += s[i] == 'a', b += s[i] == 'b', c += s[i] == 'c';
            
            while(l <= i and a and b and c) {
                sub += s.length() - i;
                a -= s[l] == 'a', b -= s[l] == 'b', c -= s[l] == 'c';    
                l++;
            }
        }
        
        return sub;
    }
};