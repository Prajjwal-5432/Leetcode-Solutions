//Link: https://leetcode.com/problems/palindrome-partitioning-iii/

int dp[111][111];

class Solution {
public:
    int k;
    int cnt(int i, int j, string &s) {
        int tot = 0;
        while(i <= j) {
            tot += (s[i++] != s[j--]);
        }
        return tot;
    }
    int dfs(int ind, int cuts, string &s) {
        if(ind >= s.length()) return cuts == k ? 0 : 1234;
        if(dp[ind][cuts] != -1) return dp[ind][cuts];
        
        int ans = 1234;
        for(int i = ind; i < s.length(); ++i) {
            ans = min(ans, cnt(ind, i, s) + dfs(i + 1, cuts + 1, s));
        }
        return dp[ind][cuts] = ans;
    }
    int palindromePartition(string s, int k) {
        this->k = k;
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, s);
    }
};