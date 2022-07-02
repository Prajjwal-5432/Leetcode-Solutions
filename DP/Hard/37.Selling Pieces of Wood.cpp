//Link: https://leetcode.com/problems/selling-pieces-of-wood/

#define ll long long
const int nx = 222;
ll cost[nx][nx], dp[nx][nx];

class Solution {
public:
    ll dfs(int n, int m) {
        if(n == 1 and m == 1) return cost[1][1];
        if(dp[n][m] != -1) return dp[n][m];
        
        ll ans = cost[n][m];
        for(int i = 1; i < n; ++i)
            ans = max(ans, dfs(n - i, m) + dfs(i, m));
        for(int i = 1; i < m; ++i) 
            ans = max(ans, dfs(n, m - i) + dfs(n, i));
        
        return dp[n][m] = ans;
    }
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(dp, -1, sizeof dp);
        memset(cost, 0, sizeof cost);
        
        swap(m, n);
        for(auto x: prices) cost[x[0]][x[1]] = x[2];
        
        return dfs(n, m);
    }
};