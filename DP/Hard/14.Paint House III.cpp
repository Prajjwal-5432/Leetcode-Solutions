//Link: https://leetcode.com/problems/paint-house-iii/

int dp[101][21][101];

class Solution {
public:
    int n, target, m;
    vector<vector<int>> cost;
    vector<int> houses;
    
    int func(int ind, int prev, int tot) {
        if(ind == m) return target == tot ? 0 : INT_MAX / 2;
        if(dp[ind][prev][tot] != -1) return dp[ind][prev][tot];
        
        int ans = INT_MAX / 2;
        if(houses[ind] != 0) {
            ans = min(ans, func(ind + 1, houses[ind] - 1, tot + (houses[ind] - 1 != prev)));
        } else {
            for(int i = 0; i < n; ++i)
                ans = min(ans, func(ind + 1, i, tot + (i != prev)) + cost[ind][i]);
        }
        
        return dp[ind][prev][tot] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->n = n;
        this->m = m;
        this->target = target;
        this->cost = cost;
        this->houses = houses;
        memset(dp, -1, sizeof dp);
        
        int ans = INT_MAX / 2;
        if(houses[0] != 0) {
            ans = min(ans, func(1, houses[0] - 1, 1));
        } else {
            for(int i = 0; i < n; ++i)
                ans = min(ans, func(1, i, 1) + cost[0][i]);
        }
        
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};