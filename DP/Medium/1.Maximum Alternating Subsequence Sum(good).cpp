//Link: https://leetcode.com/problems/maximum-alternating-subsequence-sum/

class Solution {
public:
    const static int nx = 1e5 + 100;
    long long dp[nx][2];
    vector<int> nums;
    
    long long func(int ind, int sign) {
        if(ind >= nums.size()) return 0;
        if(dp[ind][sign] != -1) return dp[ind][sign];
        
        long long ans = 0;
        if(sign) {
            ans = max(ans, nums[ind] + func(ind + 1, 0));
        } else {
            ans = max(ans, -nums[ind] + func(ind + 1, 1));
        }
        
        ans = max(ans, func(ind + 1, sign));
        
        return dp[ind][sign] = ans;
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        this->nums = nums;
        memset(dp, -1, sizeof dp);
        
        return func(0, 1);
    }
};