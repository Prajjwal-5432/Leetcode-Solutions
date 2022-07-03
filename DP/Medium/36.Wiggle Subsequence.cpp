//Link: https://leetcode.com/problems/wiggle-subsequence/

int dp[1111][2];
class Solution {
public:
    vector<int> nums;
    int n;
    
    int dfs(int ind, int sign) {
        if(dp[ind][sign] != -1) return dp[ind][sign];
        
        int x = sign ? 1 : -1;
        int ans = 1;
        for(int i = ind + 1; i < n; ++i) {
            if(x == 1) {
                if(nums[i] - nums[ind] < 0) ans = max(ans, 1 + dfs(i, sign ^ 1));
            } else {
                if(nums[i] - nums[ind] > 0) ans = max(ans, 1 + dfs(i, sign ^ 1));
            }
        }
        
        return dp[ind][sign] = ans;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        this->nums = nums;
        n = nums.size();
        
        int ans = 1;
        for(int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i, 0));
            ans = max(ans, dfs(i, 1));
        }
        
        return ans;
    }
};