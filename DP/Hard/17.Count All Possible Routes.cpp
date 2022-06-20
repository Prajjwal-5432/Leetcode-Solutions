//Link: https://leetcode.com/problems/count-all-possible-routes/

#define ll long long
ll dp[111][222];
ll mod;

class Solution {
public:
    vector<int> locations;
    int finish;
    
    ll dfs(int ind, int fuel) {
        if(dp[ind][fuel] != -1) return dp[ind][fuel];
        
        ll ans = 0;
        if(ind == finish) ans++;
        
        for(int i = 0; i < locations.size(); ++i) {
            if(i == ind) continue;
            if(abs(locations[i] - locations[ind]) <= fuel) 
                ans = (ans + dfs(i, fuel - abs(locations[i] - locations[ind]))) % mod;
        }
        
        return dp[ind][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        mod = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        this->locations = locations;
        this->finish = finish;
        
        return dfs(start, fuel);
    }
};