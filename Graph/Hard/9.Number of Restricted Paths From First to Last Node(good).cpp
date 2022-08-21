//Link: https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

#define ll long long
class Solution {
public:
    vector<ll> d;
    vector<vector<pair<ll, ll>>> graf;
    vector<ll> dp;
    ll mod = 1e9 + 7;
    
    void dij(int src) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto [dis, v] = pq.top();
            pq.pop();
            
            if(dis > d[v]) continue;
            
            for(auto [x, y]: graf[v]) {
                if(d[v] + y < d[x]) {
                    d[x] = d[v] + y;
                    pq.push({d[x], x});
                }
            }
        }
    }
    ll dfs(int v) {
        if(v == 0) return 1;
        if(dp[v] != -1) return dp[v];

        ll ans = 0;
        for(auto [x, y]: graf[v]) {
            if(d[x] > d[v]) ans = (ans + dfs(x)) % mod;
        }
        return dp[v] = ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        d.resize(n, LONG_MAX);
        graf.resize(n);
        dp.resize(n, -1);
        
        for(auto x: edges) {
            int u = x[0] - 1, v = x[1] - 1, cost = x[2];
            graf[u].push_back({v, cost});
            graf[v].push_back({u, cost});
        }
        
        d[n - 1] = 0;
        dij(n - 1);
        return dfs(n - 1);
    }
};