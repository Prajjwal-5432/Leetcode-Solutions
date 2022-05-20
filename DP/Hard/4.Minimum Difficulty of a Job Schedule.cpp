//Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

int dp[350][12];

class Solution {
public:
    vector<int> nums;
    int n;
    
    int func(int ind, int d) {
        if(ind == n) return d ? INT_MAX / 2 : 0;
        if(d == 0) return INT_MAX / 2;
        if(dp[ind][d] != -1) return dp[ind][d];
        
        int ans = INT_MAX / 2, mx = 0;
        for(int i = ind; i < n; ++i) {
            mx = max(mx, nums[i]);
            ans = min(ans, mx + func(i + 1, d - 1));
        }
        
        return dp[ind][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof dp);
        this->nums = jobDifficulty;
        this->n = nums.size();
        
        if(d > n) return -1;
        
        return func(0, d);
    }
};