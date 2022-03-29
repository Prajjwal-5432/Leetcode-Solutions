//Link: https://leetcode.com/problems/maximize-score-after-n-operations/

class Solution {
public:
    int dp[1 << 15][9];
    unordered_map<int, int> mp;
    vector<int> comb;
    
    int func(int mask, int i) {
        if(mask == 0) return 0;
        if(dp[mask][i] != -1) return dp[mask][i];
        
        int ans = INT_MIN / 2;
        for(auto c: comb) {
            if((mask & c) == c) {
                ans = max(ans, i * mp[c] + func(mask ^ c, i + 1));
            }
        }
        
        return dp[mask][i] = ans;
    }
    
    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        
        int n = nums.size();
        for(int mask = 0; mask < (1 << n); ++mask) {
            int bits = __builtin_popcount(mask);
            
            if(bits == 2) {
                vector<int> v;
                for(int j = 0, val = mask; val; ++j, val >>= 1) {
                    if(val & 1)
                        v.push_back(nums[j]);
                }
                mp[mask] = __gcd(v[0], v[1]);
                comb.push_back(mask);
            }
        }    
        
        return func((1 << n) - 1, 1);
    }
};