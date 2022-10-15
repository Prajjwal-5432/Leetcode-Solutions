//Link: https://leetcode.com/problems/string-compression-ii/

class Solution {
public:
    int dp[111][111];
    int len(int val) {
        return val == 1 ? 0 : val < 10 ? 1 : val < 100 ? 2 : 3;
    }
    int dfs(string &s, int ind, int k) {
        if(k < 0) return INT_MAX / 2;
        if(ind >= s.length() or s.length() - ind <= k) return 0;
        
        int &res = dp[ind][k];
        if(res != -1) return res;
        
        res = INT_MAX / 2;
        vector<int> cnt(26, 0);
        for(int i = ind, most = 0; i < s.length(); ++i) {
            most = max(most, ++cnt[s[i] - 'a']);
            res = min(res, 1 + len(most) + dfs(s, i + 1, k - (i - ind + 1 - most)));
        }
        return res;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        return dfs(s, 0, k);
    }
};