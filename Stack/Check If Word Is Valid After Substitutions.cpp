//Link: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
class Solution {
public:
    bool isValid(string s) {
        vector<string> st;
        
        for(auto x: s) {
            if(x == 'a') st.push_back(string(1, x));
            else if(x == 'b') {
                if(!st.empty() and st.back() == "a") st.back() += x;
                else return false;
            } else if(x == 'c') {
                if(!st.empty() and st.back() == "ab") st.pop_back();
                else return false;
            }
        }
        
        return st.empty();
    }
};