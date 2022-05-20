//Link: https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/

#define ll long long
const int nx = 230;

ll dp[nx][nx];

class Solution {
public:
    vector<int> nums;
    int n;
    
    ll func(int ind, int k) {
        if(ind == n) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        ll sum = 0, mx = 0, ans = INT_MAX;
        
        for(int i = ind; i < n; ++i) {
            sum += nums[i];
            if(nums[i] > mx) mx = nums[i];       

            if(k) ans = min(ans, mx * (i - ind + 1) - sum + func(i + 1, k - 1));
            else ans = mx * (i - ind + 1) - sum;
        }
        
        return dp[ind][k] = ans;
    }
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp, -1, sizeof dp);
        this->nums = nums;
        this->n = nums.size();
        
        return func(0, k);
    }
};