//Link: https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/

class Solution {
public:
    int minimumBuckets(string s) {
        if(s.length() == 1 and s[0] == 'H') return -1;
        
        if(s.length() > 1) {
            if(s.substr(0, 2) == "HH") return -1;
            if(s.substr(s.size() - 2, 2) == "HH") return -1;
        }
        
        for(int i = 1; i < s.length() - 1; ++i) {
            if(s[i] == 'H' and s[i - 1] == 'H' and s[i + 1] == 'H')
                return -1;
        }
        
        int buckets = 0;
        for(int i = 1; i < s.length() - 1; ++i) {
            if(s[i] == '.' and s[i - 1] == 'H' and s[i + 1] == 'H') {
                buckets++;
                s[i - 1] = s[i + 1] = '.';   
            }
        }
        buckets += count(s.begin(), s.end(), 'H');
        
        return buckets;
    }
};