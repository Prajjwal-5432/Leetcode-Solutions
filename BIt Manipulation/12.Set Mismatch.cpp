//Link: https://leetcode.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int val = 0, n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            val ^= nums[i] ^ (i + 1);
        }
        
        int rsb = val & -val;
        
        int x = 0, y = 0;
        
        for(int i = 0; i < n; ++i) {
            if((rsb & nums[i]) == 0) x ^= nums[i];
            else y ^= nums[i];
            
            if(((i + 1) & rsb) == 0) x ^= (i + 1);
            else y ^= (i + 1);
        }
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] == x) return {x, y};
            else if(nums[i] == y) return {y, x};
        }
        return {};
    }
};