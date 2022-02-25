//Link: https://leetcode.com/problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        if(path.back() != '\/') path.push_back('\/');
        vector<string> v;
        
        for(int i = 0; i < path.length(); ++i) {
            char x = path[i];
            if(x == '\/') {
                if(v.empty() or v.back() != "\/") v.push_back(string(1, x));
            } else {
                string t;
                while(path[i] != '\/') t += path[i++];
                i--;
                
                if(t == ".") continue;
                
                if(t == "..") {
                    if(v.size() > 1) v.pop_back(), v.pop_back();
                    else if(!v.empty()) v.pop_back();
                    if(v.empty()) v.push_back(string(1, '\/'));
                } else {
                    v.push_back(t);
                }
            }
        }
        
        string s;
        for(auto x: v) s += x;
        if(s.length() > 1 and s.back() == '\/') s.pop_back();
        return s;
    }
};