//Link: https://leetcode.com/problems/matchsticks-to-square/

class Solution {
public:
    int n, line;
    vector<int> matchsticks;
    unordered_map<string, bool> dp;
    
    string convert(int ind, vector<int> v) {
        string s = to_string(ind) + "*";
        sort(v.begin(), v.end());
        
        for(auto x: v) s += to_string(x) + "*";
        
        return s;
    }
    
    bool func(int ind, int line1, int line2, int line3, int line4) {
        if(ind == n) return (line1 == line2 and line3 == line4 and line2 == line3);
        if(max({line1, line2, line3, line4}) > line) return 0;
        
        string key = convert(ind, {line1, line2, line3, line4});
        
        if(dp.count(key)) return dp[key];
        
        int ans = 0, val = matchsticks[ind];
        
        ans |= func(ind + 1, line1 + val, line2, line3, line4);
        if(!ans) ans |= func(ind + 1, line1, line2 + val, line3, line4);
        if(!ans) ans |= func(ind + 1, line1, line2, line3 + val, line4);
        if(!ans) ans |= func(ind + 1, line1, line2, line3, line4 + val);
        
        return dp[key] = ans;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int tot = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        if(tot % 4 != 0) return 0;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        this->matchsticks = matchsticks;
        n = matchsticks.size();
        line = tot / 4;
        
        return func(0, 0, 0, 0, 0);
    }
};