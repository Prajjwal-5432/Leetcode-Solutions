//Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, int>> v;
        
        for(auto x: s) {
            if(v.empty() or v.back().first != x) v.push_back({x, 1});
            else v.back().second++;
            
            if(v.back().second == k) v.pop_back();
        }
        
        s.clear();
        for(auto x: v) s += string(x.second, x.first);
        
        return s;
    }
};