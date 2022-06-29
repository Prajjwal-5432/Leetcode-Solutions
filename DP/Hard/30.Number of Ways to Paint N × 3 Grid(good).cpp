//Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/

#define ll long long
#define rep(i, a, b) for(int i = a; i < b; ++i)
ll dp[5555][4][4][4];
ll mod;

class Solution {
public:
    ll dfs(int ind, int ca, int cb, int cc, int n) {
        if(ind == n) return 1;
        if(dp[ind][ca][cb][cc] != -1) return dp[ind][ca][cb][cc];
        
        ll ans = 0;
        rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) {
            if(i != j and j != k and i != ca and j != cb and k != cc) 
                ans = (ans + dfs(ind + 1, i, j, k, n)) % mod;
        }
        
        return dp[ind][ca][cb][cc] = ans;
    }
    int numOfWays(int n) {
        mod = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        
        ll ans = 0;
        
        rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) {
            if(i != j and j != k) ans = (ans + dfs(1, i, j, k, n)) % mod;
        }
        
        return ans;
    }
};