//Link: https://leetcode.com/problems/longest-chunked-palindrome-decomposition/

class Solution {
public:
    int dp[1111][1111];
    string s;
    
    int dfs(int i, int j) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        int l = i, r = j, best = 1;
        while(l < r) {
            if(s.substr(i, l - i + 1) == s.substr(r, l - i + 1)) 
                best = max(best, 2 + dfs(l + 1, r - 1));
            l++, r--;
        }
        
        return dp[i][j] = best;
    }
    
    int longestDecomposition(string text) {
        memset(dp, -1, sizeof dp);      
        s = text;
        
        return dfs(0, s.length() - 1);
    }
};