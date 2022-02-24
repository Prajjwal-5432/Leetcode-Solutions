//Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder += ',';
        
        vector<string> pre;
        
        string s;
        for(int i = 0; i < preorder.length(); ++i) {
            if(preorder[i] == ',') {
                pre.push_back(s);
                s.clear();
            } else {
                s += preorder[i];
            }
        }
        
        vector<string> st;
        
        for(int i = 0; i < pre.size(); ++i) {
            st.push_back(pre[i]);
            
            int n = st.size();
            while(n >= 3 and st[n - 1] == "#" and st[n - 2] == "#" and st[n - 3] != "#") {
                st.pop_back(), st.pop_back(), st.pop_back();
                st.push_back("#");
                n = st.size();
            }
        }
        
        return (st.size() == 1 and st[0] == "#");
    }
};