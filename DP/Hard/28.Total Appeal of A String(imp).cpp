//Link: https://leetcode.com/problems/total-appeal-of-a-string/

class Solution {
public:
    long long appealSum(string s) {
        long long res = 0;
        vector<int> lst(26, 0);
        
        for(int i = 0; i < s.length(); ++i) {
            lst[s[i] - 'a'] = i + 1;
            for(auto x: lst) res += x;
        }
        
        return res;
    }
};