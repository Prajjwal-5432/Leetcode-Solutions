//Link: https://leetcode.com/problems/count-number-of-special-subsequences/

#define ll long long
const int nx = 1e5 + 100;
ll dp[nx][8];
ll mod;
class Solution {
public:
    vector<int> nums;
  
    ll dfs(int ind, int mask) {
        ll ans = 0;
        if(mask == 7) ans++;
        if(ind == nums.size()) return ans;
        if(dp[ind][mask] != -1) return dp[ind][mask];
        
        ans = (ans + dfs(ind + 1, mask)) % mod;
        
        if(mask == 7) {
            if(nums[ind] == 2) ans = (ans + dfs(ind + 1, mask)) % mod;
        } else if(mask == 3) {
            if(nums[ind] == 1) ans = (ans + dfs(ind + 1, mask)) % mod;
            if(nums[ind] == 2) ans = (ans + dfs(ind + 1, 7)) % mod;
        } else if(mask == 1) {
            if(nums[ind] == 0) ans = (ans + dfs(ind + 1, mask)) % mod;
            if(nums[ind] == 1) ans = (ans + dfs(ind + 1, 3)) % mod;
        }
        if(mask == 7) ans--;
        return dp[ind][mask] = ans;
    }
  
    int countSpecialSubsequences(vector<int>& nums) {
        mod = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        this->nums = nums;
        
        ll ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) ans = (ans + dfs(i + 1, 1)) % mod;
        }
        
        return ans;
    }
};