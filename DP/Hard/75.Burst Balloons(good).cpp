//Link: https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int dp[333][333];
    int cost(vector<int> &nums, int i) {
        return i >= 0 and i < nums.size() ? nums[i] : 1;
    }
    int dfs(int i, int j, vector<int> &nums) {
        if(i == j) return cost(nums, i) * cost(nums, i - 1) * cost(nums, i + 1);
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        for(int k = i; k <= j; ++k) {
            int tot = cost(nums, i - 1) * cost(nums, k) * cost(nums, j + 1);
            ans = max(ans, dfs(i, k - 1, nums) + dfs(k + 1, j, nums) + tot);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return dfs(0, nums.size() - 1, nums);
    }
};