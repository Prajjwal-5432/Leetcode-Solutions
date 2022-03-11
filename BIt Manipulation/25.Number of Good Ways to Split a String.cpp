//Link: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

class Solution {
public:
    int numSplits(string s) {
        long left = 0, right = 0;
        
        vector<int> ind(26, 0);
        
        for(int i = 0; i < s.length(); ++i) ind[s[i] - 'a'] = i;
        
        for(auto x: s) right |= (1 << (x - 'a'));
        
        int cnt = 0;
        for(int i = 0; i < s.length(); ++i) {
            left |= (1 << (s[i] - 'a'));
            if(i == ind[s[i] - 'a']) right ^= (1 << (s[i] - 'a'));
            
            cnt += __builtin_popcountl(left) == __builtin_popcountl(right);
        }
        
        return cnt;
    }
};