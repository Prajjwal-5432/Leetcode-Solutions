//Link: https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<pair<char, int>> v;
        
        for(auto x: s) {
            if(x == '(') v.push_back({'(', 0});
            else {
                if(!v.empty() and v.back().first == '(') {
                    int extra = v.back().second;
                    v.pop_back();
                    if(v.empty()) v.push_back({'.', 2});
                    else v.back().second += 2;
                    v.back().second += extra;
                } else {
                    v.push_back({x, 0});
                }
            }
        }
        int mx = 0, res = 0;
        for(auto x: v) {
            res = x.first == '.' ? res + x.second : x.second;
            mx = max(mx, res);
        }
        
        return mx;
    }
};