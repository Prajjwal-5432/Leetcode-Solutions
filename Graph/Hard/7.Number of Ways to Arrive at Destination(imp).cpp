//Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> graf(n);
        
        for(auto x: roads) {
            graf[x[0]].push_back({x[1], x[2]});
            graf[x[1]].push_back({x[0], x[2]});
        }
        
        vector<long long > d(n, LONG_MAX), dp(n, 0);
        dp[0] = 1;
        d[0] = 0;
        long long mod = 1e9 + 7;
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto [dis, v] = pq.top();
            pq.pop();
            if(dis > d[v]) continue;
            for(auto [x, y]: graf[v]) {
                if(d[v] + y < d[x]) {
                    d[x] = d[v] + y;
                    dp[x] = dp[v];
                    pq.push({d[x], x});
                } else if(dis + y == d[x]) {
                    dp[x] = (dp[x] + dp[v]) % mod;
                }
            }
        }
        
        return dp[n - 1];
    }
};