//Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {
public:
    int sum = 0;
    vector<int> nums;
    
    void combo(int idx, int cur) {
        if(idx == nums.size()) {
            sum += cur;
            return;
        }
        
        combo(idx + 1, cur ^ nums[idx]);
        combo(idx + 1, cur);
    }
    
    int subsetXORSum(vector<int>& nums) {
        this->nums = nums;
        
        combo(0, 0);
        
        return sum;
    }
};