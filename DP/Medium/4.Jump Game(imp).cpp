//Link: https://leetcode.com/problems/jump-game/
//DP is O(N^2)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, n = nums.size();
        for(int next = 0; i < n and i <= next; ++i) {
            next = max(i + nums[i], next);
        }
        
        return i == n;
    }
};