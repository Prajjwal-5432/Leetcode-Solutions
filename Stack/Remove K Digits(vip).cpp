//Link: https://leetcode.com/problems/remove-k-digits/
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        
        for(auto x: num) {
            if(st.empty() and x != '0') st.push_back(x);
            else if(!st.empty() and x >= st.back()) st.push_back(x);
            else {
                while(!st.empty() and k and x < st.back()) st.pop_back(), k--;
                if(st.empty() and x == '0') continue;
                st.push_back(x);
            }
        }
        
        while(!st.empty() and k) st.pop_back(), k--;
        
        num.clear();
        for(auto x: st) num += x;
        
        if(num.empty()) num = "0";
        
        return num;
    }
};