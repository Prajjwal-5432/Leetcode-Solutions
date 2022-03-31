//Link: https://leetcode.com/problems/maximum-and-sum-of-array/
//Refer: https://leetcode.com/problems/maximum-and-sum-of-array/discuss/1775311/Dp-with-bitmasking-faster-than-93.52-of-submissions

class Solution {
public:
    int dp[(1 << 18) + 1];
    vector<int> nums;
    int ns;
    
    int func(int ind, int mask) {
        if(ind == nums.size()) return 0;
        if(dp[mask] != -1) return dp[mask];
        
        int ans = INT_MIN;
        
        for(int i = 0; i < ns; ++i) {
            int pos = 2 * i;
            
            if(((mask >> pos) & 1) == 0) {
               ans = max(ans, func(ind + 1, mask | (1 << pos)) + (nums[ind] & (i + 1))); 
            } else {
                pos++;
                if(((mask >> pos) & 1) == 0) {
                    ans = max(ans, func(ind + 1, mask | (1 << pos)) + (nums[ind] & (i + 1))); 
                }
            }
        }
        
        return dp[mask] = ans;
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        memset(dp, -1, sizeof(dp));
        this->nums = nums;
        this->ns = numSlots;
        
        return func(0, 0);
    }
};