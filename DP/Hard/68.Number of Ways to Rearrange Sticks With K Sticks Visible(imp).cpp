//Link: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/

#define ll long long
ll dp[1111][1111];
ll mod;

class Solution {
public:
    ll dfs(int n, int k) {
        if(n == k) return 1;
        if(n == 0 or k == 0) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        return dp[n][k] = ((n - 1) * dfs(n - 1, k) % mod + dfs(n - 1, k - 1)) % mod;
    }
    int rearrangeSticks(int n, int k) {
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
        return dfs(n, k);
    }
};