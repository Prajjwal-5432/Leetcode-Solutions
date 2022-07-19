//Link: https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int cost(vector<int> &nums, int i) {
        return (i >= 0 and i < nums.size()) ? nums[i] : 1;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        
        for(int gap = 0; gap < n; ++gap) {
            for(int i = 0, j = gap; j < n; ++i, ++j) {
                if(gap == 0) {
                    dp[i][j] = cost(nums, i) * cost(nums, i - 1) * cost(nums, i + 1);
                } else {
                    for(int k = i; k <= j; ++k) {
                        int tot = cost(nums, k) * cost(nums, i - 1) * cost(nums, j + 1);
                        if(k == i) {
                            dp[i][j] = max(dp[i][j], dp[k + 1][j] + tot);
                        } else if(k == j) {
                            dp[i][j] = max(dp[i][j], dp[i][k - 1] + tot);
                        } else {
                            dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + tot);
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};