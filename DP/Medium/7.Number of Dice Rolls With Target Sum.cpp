//Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    #define ll long long
    
    ll dp[32][1100];
    ll mod, k, n;
    
    ll rundp(int ind, int target) {
        if(target < 0) return 0;
        if(target == 0) return ind == n;
        if(ind >= n) return target == 0;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        ll ans = 0;
        for(int i = 1; i < k + 1; ++i) {
            ans = (ans + rundp(ind + 1, target - i)) % mod;
        }
        
        return dp[ind][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof dp);    
        mod = 1e9 + 7;
        this->k = k;
        this->n = n;
        
        return rundp(0, target);
    }
};