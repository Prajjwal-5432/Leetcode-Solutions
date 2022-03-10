//Link: https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int val = 0;
        for(auto x: s) val ^= (x - 'a');
        for(auto x: t) val ^= (x - 'a');
        
        return char(val + 'a');
    }
};