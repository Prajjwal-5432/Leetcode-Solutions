//Link: https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
public:
    #define ll long long
    
    const static int nx = 1e5 + 100;
    ll dp[nx];
    vector<vector<int>> ques;
    
    ll func(int ind) {
        if(ind >= ques.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        ll ans = ques[ind][0] + func(ind + ques[ind][1] + 1);
        ans = max(ans, func(ind + 1));
        
        return dp[ind] = ans;
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof dp);
        ques = questions;
        
        return func(0);
    }
};