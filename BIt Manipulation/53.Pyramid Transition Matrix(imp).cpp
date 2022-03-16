//Link: https://leetcode.com/problems/pyramid-transition-matrix/

class Solution {
public:
    unordered_set<string> dp;
    unordered_map<string, vector<char>> mp;
    
    bool check(string bottom, int start, string nextRow) {
        if(bottom.length() == 1) return true;
        if(dp.count(bottom)) return false;
        
        if(start + 1 == bottom.length()) return check(nextRow, 0, "");
        
        string s = bottom.substr(start, 2);
        for(auto x: mp[s]) {
            if(check(bottom, start + 1, nextRow + x)) return 1;
        }
        
        dp.insert(bottom);
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) { 
        for(auto x: allowed) mp[x.substr(0, 2)].push_back(x[2]);
        return check(bottom, 0, "");
    }
};