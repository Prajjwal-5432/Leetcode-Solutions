//Link: https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnt(26, 0);
        for(auto x: s) cnt[x - 'a']++;
        
        string ans;
        for(auto x: order) {
            ans += string(cnt[x - 'a'], x);
            cnt[x - 'a'] = 0;
        }
        
        for(int i = 0; i < 26; ++i)
            ans += string(cnt[i], char(i + 'a'));
        
        return ans;
    }
};