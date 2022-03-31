//Link: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
//We don't need to memoize ind coz its unique

class Solution {
public:
    int dp[1 << 14 + 1];
    vector<int> a, b;
    
    int func(int ind, int mask) {
        if(ind == a.size()) return 0;
        if(dp[mask] != -1) return dp[mask];
        
        int ans = INT_MAX / 2;
        
        for(int j = 0; j < b.size(); ++j) {
            if(((mask >> j) & 1) == 0) 
                ans = min(ans, (b[j] ^ a[ind]) + func(ind + 1, mask | (1 << j)));
        }
        
        return dp[mask] = ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        this->a = nums1;
        this->b = nums2;
        memset(dp, -1, sizeof(dp));
        
        return func(0, 0);
    }
};