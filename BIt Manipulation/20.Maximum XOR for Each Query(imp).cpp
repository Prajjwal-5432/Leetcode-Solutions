//Link: https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int bit = (1 << maximumBit) - 1;
        
        int val = 0;
        vector<int> ans;
        
        for(auto x: nums) {
            val ^= x;
            
            int bit_ = bit, val_ = val, number = 0;
            for(int i = 0; bit_ or val_; bit_ >>= 1, val_ >>= 1, ++i) {
                int numbit = val_ & 1;
                
                if(numbit == 0) number |= (1 << i);
                else number &= ~(1 << i);
            }
            ans.push_back(number);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};