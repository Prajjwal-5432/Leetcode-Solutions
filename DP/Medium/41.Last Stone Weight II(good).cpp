//Link: https://leetcode.com/problems/last-stone-weight-ii/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp(sum / 2 + 1);
        
        for(int i = 0; i < n; ++i) {
            for(int j = sum / 2; j >= stones[i]; --j) {
                dp[j] = max(dp[j], stones[i] + dp[j - stones[i]]);
            }
        }
        
        return sum - 2 * dp[sum / 2];
    }
};