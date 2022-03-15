//Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k) return 0;
        
        unordered_set<int> st;
        long num = 0;
        
        for(int i = 0; i < k - 1; ++i, num <<= 1) {
            num |= (s[i] == '1');
        }
        
        long mask = (1L << k) - 1;
        for(int i = k - 1; i < s.length(); ++i, num <<= 1) {
            num |= (s[i] == '1');
            num &= mask;
            
            st.insert(num);
        }
        
        if(st.size() == (1L << k)) return 1;
        
        return 0;
    }
};