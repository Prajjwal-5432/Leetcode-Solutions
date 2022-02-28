//Link: https://leetcode.com/problems/maximum-score-from-removing-substrings/
//Try both possiblities first pop ab then ba
//then try popping ba then ab

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        string t = "ab";
        
        int mx = 0;
        for(int tt = 0; tt < 2; ++tt, swap(x, y), swap(t[0], t[1])) {
            vector<char> st;
            
            int points = 0;
            for(int i = 0; i < s.length(); ++i) {
                if(!st.empty() and st.back() == t[0] and s[i] == t[1]) points += x, st.pop_back();
                else st.push_back(s[i]);
            }
            
            vector<char> v;
            for(int i = 0; i < st.size(); ++i) {
                if(!v.empty() and v.back() == t[1] and st[i] == t[0]) points += y, v.pop_back();
                else v.push_back(st[i]);
            }
            
            mx = max(mx, points);
        }
        
        return mx;
    }
};