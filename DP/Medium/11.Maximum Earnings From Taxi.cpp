//Link: https://leetcode.com/problems/maximum-earnings-from-taxi/

class Solution {
public:
    #define ll long long
    
    const static int nx = 1e5 + 100;
    
    ll dp[nx];
    ll n;
    vector<vector<pair<int, int>>> passenger;
    
    ll func(int ind) {
        if(ind > n) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        long long ans = func(ind + 1);
        
        for(auto x: passenger[ind]) {
            ans = max(ans, x.first - ind + x.second + func(x.first));
        }
        
        return dp[ind] = ans;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        this->n = n;
        passenger.resize(n + 1);
        
        for(auto x: rides) {
            passenger[x[0]].push_back({x[1], x[2]});
        }
        
        memset(dp, -1, sizeof dp);
        
        return func(0);
    }
};