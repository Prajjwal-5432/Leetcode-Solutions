//Link: https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int64_t ans = 0;
        
        for(int i = 0; i < 64; ++i) {
            int64_t zeros = 0, ones = 0;
            for(auto x: nums) {
                if(x & (1LL << i)) ones++;
                else zeros++;
            }
            ans += zeros * ones;
        }
        
        return ans;
    }
};