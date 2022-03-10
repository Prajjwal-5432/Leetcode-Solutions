//Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

//DP solution
//Recursive runs faster

class Solution {
public:
    vector<int> nums;
    vector<vector<int>> dp;
    int mx;
    
    int go(int i, int val) {
        if(dp[i][val] != -1) return dp[i][val];
        
        if(i == nums.size()) return dp[i][val] = (val == mx);
        
        return dp[i][val] = go(i + 1, val | nums[i]) + go(i + 1, val);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int val = 0, n = nums.size();
        for(auto x: nums) val |= x;
        
        mx = val;
        dp.resize(n + 1, vector<int> (val + 1, -1));
        this->nums = nums;
        
        return go(0, 0);
    }
};