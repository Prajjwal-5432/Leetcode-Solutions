//Link: https://leetcode.com/problems/palindrome-partitioning-ii/

int dp[2222];
class Solution {
public:
    bool isPal(int i, int j, string& s) {
        while(i <= j) {
            if(s[i] != s[j]) return 0;
            i++, j--;
        }
        return 1;
    }
    int dfs(int ind, string &s) {
        if(ind >= s.length()) return -1;
        if(dp[ind] != -1) return dp[ind];
        
        int cuts = 12345;
        for(int i = ind; i <= s.length(); ++i) {
            if(isPal(ind, i, s)) 
                cuts = min(cuts, 1 + dfs(i + 1, s));
        }
        return dp[ind] = cuts;
    }
    int minCut(string s) {
        memset(dp, -1, sizeof dp);
        return dfs(0, s);
    }
};