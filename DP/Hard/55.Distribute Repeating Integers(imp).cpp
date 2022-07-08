//Link: https://leetcode.com/problems/distribute-repeating-integers/

class Solution {
public:
    vector<int> freq;
    vector<int> subset;
    int dp[55][1 << 11];
    
    bool dfs(int ind, int mask) {
        if(mask == 0) return 1;
        if(ind >= freq.size()) return 0;
        if(dp[ind][mask] != -1) return dp[ind][mask];
        
        int ans = dfs(ind + 1, mask);
        for(int submask = mask; submask; submask = (submask - 1) & mask) {
            if(subset[submask] <= freq[ind]) {
                ans |= dfs(ind + 1, mask ^ submask);
            }
            if(ans) break;
        }
        return dp[ind][mask] = ans;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for(auto x: nums) mp[x]++;
        for(auto [x, y]: mp) freq.push_back(y);
        
        int n = quantity.size();
        subset.resize(1 << n, 0);
        
        for(int i = 0; i < (1 << n); ++i) {
            for(int j = 0, val = i; val; ++j, val >>= 1) {
                if(val & 1) subset[i] += quantity[j];
            }
        }
        
        memset(dp, -1, sizeof dp);
        
        return dfs(0, (1 << n) - 1);
    }
};