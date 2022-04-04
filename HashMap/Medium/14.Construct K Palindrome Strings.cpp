//Link: https://leetcode.com/problems/construct-k-palindrome-strings/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()) return 0;
        
        vector<int> cnt(26, 0);
        for(auto x: s) cnt[x - 'a']++;
        
        int od = 0;
        for(auto x: cnt)
            od += (x & 1);
        
        return od <= k;
    }
};