//Link: https://leetcode.com/problems/remove-duplicate-letters/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> index;
        for(int i = 0; i < s.length(); ++i) index[s[i]] = i;
        
        vector<int> vis(26, 0);
        vector<char> st;
        
        for(int i = 0; i < s.length(); ++i) {
            if(vis[s[i] - 'a']) continue;
            else {
                while(!st.empty() and st.back() > s[i] and index[st.back()] > i) {
                    vis[st.back() - 'a'] = 0;
                    st.pop_back();
                }
                st.push_back(s[i]);
                vis[s[i] - 'a'] = 1;
            }
        }
        
        s.clear();
        for(auto x: st) s += x;
        
        return s;
    }
};