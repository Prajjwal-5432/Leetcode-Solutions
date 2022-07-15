//Link: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

int dp[200013][2];

class Solution {
public:
    int dfs(int ind, int prev, vector<int> &nums1, vector<int> &nums2) {
        if(ind >= nums1.size()) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        int x, y, ans = INT_MAX / 2;
        if(prev) x = nums2[ind - 1], y = nums1[ind - 1];
        else x = nums1[ind - 1], y = nums2[ind - 1];
        
        if(nums1[ind] > x and nums2[ind] > y)
            ans = min(ans, dfs(ind + 1, 0, nums1, nums2));
        if(nums2[ind] > x and nums1[ind] > y)
            ans = min(ans, 1 + dfs(ind + 1, 1, nums1, nums2));
        
        return dp[ind][prev] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);        
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        return dfs(1, 0, nums1, nums2);
    }
};