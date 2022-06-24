//Link: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

class Solution {
public:
    int dp[111][111];
    vector<vector<int>> v;
    
    int dfs(int ind, int prev) {
        if(ind == v.size()) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        int ans = dfs(ind + 1, prev);
        if(v[ind][0] >= v[prev][0] and v[ind][1] >= v[prev][1] and v[ind][2] >= v[prev][2]) {
            ans = max(ans, v[ind][2] + dfs(ind + 1, ind));
        }
        
        return dp[ind][prev] = ans;
    }
  
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &x: cuboids) sort(x.begin(), x.end());
        
        sort(cuboids.begin(), cuboids.end(), [&](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? (a[1] == b[1] ? a[2] < b[2] : a[1] < b[1]) : a[0] < b[0]; 
        });
        
        cuboids.insert(cuboids.begin(), {0, 0, 0});
        
        v = cuboids;
        memset(dp, -1, sizeof dp);
        
        return dfs(1, 0);
    }
};