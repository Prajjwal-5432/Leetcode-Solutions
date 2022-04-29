//Link: https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        
        dp[0] = 0;
        for(auto x: coins) {
            for(int j = x; j <= amount; ++j) {
                dp[j] = min(dp[j], 1 + dp[j - x]);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};