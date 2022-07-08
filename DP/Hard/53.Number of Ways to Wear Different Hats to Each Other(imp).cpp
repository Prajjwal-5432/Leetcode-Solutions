//Link: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/

#define ll long long
ll dp[44][1 << 11];
ll mod;

class Solution {
public:
    vector<ll> person;
    int n;
    ll dfs(ll hat, ll mask) {
        if(mask == 0) return 1;
        if(hat > 40) return 0;
        
        if(dp[hat][mask] != -1) return dp[hat][mask];
        
        ll ans = dfs(hat + 1, mask);
        for(int i = 0; i < n; ++i) {
            if((mask >> i & 1) and (person[i] >> hat & 1)) {
                ans = (ans + dfs(hat + 1, mask ^ (1 << i))) % mod;
            }
        }
        
        return dp[hat][mask] = ans;
    }
    int numberWays(vector<vector<int>>& hats) {
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
        n = hats.size();
        person.resize(n);
        
        for(int i = 0; i < n; ++i) {
            for(auto x: hats[i]) person[i] |= (1LL << x);
        }
        
        return dfs(1, (1 << n) - 1);
    }
};