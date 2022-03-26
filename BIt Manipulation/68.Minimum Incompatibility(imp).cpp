//Link: https://leetcode.com/problems/minimum-incompatibility/

class Solution {
public:
    unordered_map<int, int> cost;
    vector<int> comb;
    int dp[1 << 16];
    
    int func(int mask) {
        if(mask == 0) return 0;
        if(dp[mask] != -1) return dp[mask];
        
        int ans = INT_MAX / 2;
        
        for(auto c: comb) {
            if((mask & c) == c) 
                ans = min(ans, func(mask ^ c) + cost[c]);
        }
        
        return dp[mask] = ans;
    }
    
    int minimumIncompatibility(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        
        int n = nums.size();
        int bucketSize = n / k;
        
        for(int mask = 0; mask < (1 << n); ++mask) {
            int bits = __builtin_popcount(mask);
            
            if(bits == bucketSize) {
                int seen = 0, mx = INT_MIN, mn = INT_MAX;
                bool flag = true;
                
                for(int i = 0, num = mask; num; ++i, num >>= 1) {
                    if(num & 1) {
                        if(seen & (1 << nums[i])) flag = false;
                        seen |= (1 << nums[i]);
                        mx = max(mx, nums[i]);
                        mn = min(mn, nums[i]);
                    }
                }
                
                if(flag) {
                    cost[mask] = mx - mn;
                    comb.push_back(mask);
                }
            }
        }
        
        int ans = func((1 << n) - 1);
        
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};