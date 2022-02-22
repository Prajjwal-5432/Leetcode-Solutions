//Link: https://leetcode.com/problems/score-of-parentheses/
class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<pair<char, int>> v;
        
        int mx = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') {
                v.push_back({s[i], 0});
            } else {
                if(v.back().first == '(') {
                    v.back().first = '.';
                    v.back().second++;
                } else {
                    int val = v.back().second;
                    v.pop_back();
                    v.back().second += 2 * val;
                    v.back().first = '.';
                }
            }
            if(v.size() > 1 and v[v.size() - 1].first == '.' and v[v.size() - 2].first == '.') {
                int val = v.back().second;
                v.pop_back();
                v.back().second += val;
            }
            mx = max(mx, v.back().second);
        }
        
        return mx;
    }
};