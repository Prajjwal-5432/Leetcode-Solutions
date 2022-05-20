//Link: https://leetcode.com/problems/reducing-dishes/

const int nx = 555;
int dp[nx][nx];

class Solution {
public:
    vector<int> nums;
    int n;
    
    int func(int ind, int k) {
        if(ind == n) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int ans = max(func(ind + 1, k), nums[ind] * k + func(ind + 1, k + 1));
        return dp[ind][k] = ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp, -1, sizeof dp);
        this->nums = satisfaction;
        this->n = nums.size();  
        sort(nums.begin(), nums.end());
        
        return func(0, 1);
    }
};