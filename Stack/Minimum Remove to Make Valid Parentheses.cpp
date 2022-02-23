//Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<char, int>> v;
        
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] >= 'a' and s[i] <= 'z') continue;
            if(s[i] == '(') {
                v.push_back({s[i], i});
            } else {
                if(!v.empty() and v.back().first == '(') v.pop_back();
                else v.push_back({s[i], i});
            }
        }
        
        for(int i = 0; i < v.size(); ++i) s[v[i].second] = '.';
        
        string ans;
        for(auto x: s) if(x != '.') ans += x;
        
        return ans;
    }
};