//Link: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/

#define ll long long
const int nx = 1e3 + 10;
ll dp[nx][nx];

class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> fee;
    int n;
    
    ll dfs(int v, int leftTime) {
        if(leftTime < 0) return INT_MAX / 2;
        if(v == n - 1) return (leftTime < 0) ? INT_MAX / 2 : fee[v];
        if(dp[v][leftTime] != -1) return dp[v][leftTime];
        
        ll res = INT_MAX / 2;
        for(auto [x, y]: adj[v]) {
            res = min(res, fee[v] + dfs(x, leftTime - y));
        }
        
        return dp[v][leftTime] = res;
    }
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        memset(dp, -1, sizeof dp);
        
        n = passingFees.size();   
        adj.resize(n);
        this->fee = passingFees;
        
        for(auto x: edges) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        
        ll ans = dfs(0, maxTime);
        if(ans == INT_MAX / 2) ans = -1;
        return ans;
    }
};