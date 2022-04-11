//Link: https://leetcode.com/problems/word-break/

class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, bool> dp;
    
    bool ok(string s) {
        if(s.empty()) {
            return true;
        }
        
        if(dp.count(s)) return dp[s];
        
        int i = 0;
        string t;
        while(i < s.length() and t.length() < 21) {
            t += s[i];
            if(st.count(t)) {
                if(ok(s.substr(i + 1))) return 1;
            }
            i++;
        }
        
        return dp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        st.insert(wordDict.begin(), wordDict.end());
        
        return ok(s);  
    }
};