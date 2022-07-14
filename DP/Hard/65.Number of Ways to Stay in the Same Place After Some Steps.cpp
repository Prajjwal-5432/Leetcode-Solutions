//Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

#define ll long long
ll dp[600][600];
ll mod;
class Solution {
public:
    ll dfs(int steps, int pos, int len) {
        if(pos < 0 or pos >= len) return 0;
        if(steps == 0) return pos == 0;
        if(dp[steps][pos] != -1) return dp[steps][pos];
        
        ll ans = dfs(steps - 1, pos, len);
        ans = (ans + dfs(steps - 1, pos + 1, len)) % mod;
        ans = (ans + dfs(steps - 1, pos - 1, len)) % mod;
        
        return dp[steps][pos] = ans;
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, 555);   
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
        
        return dfs(steps, 0, arrLen);
    }
};