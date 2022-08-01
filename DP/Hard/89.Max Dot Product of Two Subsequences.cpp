//Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/

class Solution {
public:
    int dp[555][555][2];
    int dfs(int i, int j, int k, vector<int> &nums1, vector<int> &nums2) {
        if(i == nums1.size() or j == nums2.size()) return k ? 0 : INT_MIN;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        int ans = dfs(i + 1, j + 1, k, nums1, nums2);
        ans = max(ans, nums1[i] * nums2[j] + dfs(i + 1, j + 1, 1, nums1, nums2));
        ans = max(ans, dfs(i, j + 1, k, nums1, nums2));
        ans = max(ans, dfs(i + 1, j, k, nums1, nums2));
        
        return dp[i][j][k] = ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, 0, nums1, nums2);
    }
};