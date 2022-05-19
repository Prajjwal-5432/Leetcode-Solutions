//Link: https://leetcode.com/problems/2-keys-keyboard/

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 2, INT_MAX / 2);
        dp[1] = dp[0] = 0;
        
        for(int i = 2; i < n + 1; ++i) {
            for(int j = 1; j * j <= i; ++j) {
                if(i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + (i / j));
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        
        return dp[n];
    }
};