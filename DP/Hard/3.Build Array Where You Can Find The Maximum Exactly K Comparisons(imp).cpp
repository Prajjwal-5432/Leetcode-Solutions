//Link: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

#define ll long long

const int nx = 150;
ll dp[nx][nx][nx];
ll mod;

class Solution {
public:
    int n, m;
    
    ll func(int ind, int mx, int k) {
        if(ind == n) return k == 0;
        if(dp[ind][mx][k] != -1) return dp[ind][mx][k];
        
        ll ans = 0;
        for(int i = 1; i <= mx; ++i)
            ans = (ans + func(ind + 1, mx, k)) % mod;
        
        if(k) {
            for(int i = mx + 1; i <= m; ++i) 
                ans = (ans + func(ind + 1, i, k - 1)) % mod;
        }
        
        return dp[ind][mx][k] = ans;
    }
    
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
        this->n = n;
        this->m = m;
        
        ll ans = 0;
        for(int i = 1; i <= m; ++i) 
            ans = (ans + func(1, i, k - 1)) % mod;
        
        return ans;
    }
};