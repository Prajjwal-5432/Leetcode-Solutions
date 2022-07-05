//Link: https://leetcode.com/problems/constrained-subsequence-sum/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<long long> dq;
        vector<long long> dp(n, 0);
        
        dp[0] = nums[0];
        dq.push_back(nums[0]);
        
        for(int i = 1; i < n; ++i) {
            if(i - k > 0 and !dq.empty() and dq.front() == dp[i - k - 1]) dq.pop_front();
            
            dp[i] = max(nums[i] + dq.front(), 1LL * nums[i]);
            while(!dq.empty() and dp[i] > dq.back()) dq.pop_back();
            dq.push_back(dp[i]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};