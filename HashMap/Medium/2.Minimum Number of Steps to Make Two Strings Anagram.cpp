//Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26, 0), b(26, 0);
        
        for(auto x: s) a[x - 'a']++;
        for(auto x: t) b[x - 'a']++;
        
        int change = 0;
        for(int i = 0; i < 26; ++i) {
            change += max(a[i] - b[i], 0);
        }
        
        return change;
    }
};