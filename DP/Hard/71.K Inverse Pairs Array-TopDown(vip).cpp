//Link: https://leetcode.com/problems/k-inverse-pairs-array/

#define ll long long
ll dp[1111][1111];
ll mod;

class Solution {
public:
    int n;
    ll dfs(int ind, int k) {
        if(ind == 0) return 0;
        if(k == 0) return 1;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        ll ans = (dfs(ind - 1, k) - ((k >= ind) ? dfs(ind - 1, k - ind) : 0) + mod) % mod;
        ans = (ans + dfs(ind, k - 1)) % mod;
        
        return dp[ind][k] = ans;
    }
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
        this->n = n;
        
        return (dfs(n, k) - (k ? dfs(n, k - 1) : 0) + mod) % mod;
    }
};
