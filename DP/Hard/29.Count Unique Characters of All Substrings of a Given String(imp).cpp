//Link: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> mp;
        
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            if(mp[s[i]].empty()) mp[s[i]].push_back(-1);
            mp[s[i]].push_back(i);
        }
  
        for(auto x: mp) mp[x.first].push_back(n);
        
        long long res = 0;
        for(auto [x, y]: mp) {
            for(int i = 1; i < y.size() - 1; ++i) res += 1LL * (y[i] - y[i - 1]) * (y[i + 1] - y[i]);
        }
        
        return res;
    }
};