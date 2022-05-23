//Link: https://leetcode.com/problems/profitable-schemes/

#define ll long long
const int nx = 200;
ll dp[nx][nx][nx];
ll mod;

class Solution {
public:
    vector<int> grp, prof;
    int n, minProfit;
    
    int func(int ind, int people, int profit) {
        if(ind == grp.size()) {
            return (people <= n and profit >= minProfit);
        }
        if(dp[ind][people][profit] != -1) return dp[ind][people][profit];
        
        int ans = func(ind + 1, people, profit);
        if(people + grp[ind] <= n) {
            ans = (ans + func(ind + 1, people + grp[ind], min(profit + prof[ind], minProfit))) % mod;   
        }
        
        return dp[ind][people][profit] = ans;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof dp);
        this->grp = group;
        this->prof = profit;
        this->n = n;
        this->minProfit = minProfit;
        mod = 1e9 + 7;
        
        return func(0, 0, 0);
    }
};