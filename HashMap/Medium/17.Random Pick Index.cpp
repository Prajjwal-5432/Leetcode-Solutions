//Link: https://leetcode.com/problems/random-pick-index/

class Solution {
public:
    unordered_map<int, pair<vector<int>, int>> mp;
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].first.push_back(i);
            mp[nums[i]].second = 0;
        }
    }
    
    int pick(int target) {
        int ind = mp[target].first[mp[target].second];
        mp[target].second = (mp[target].second + 1) % mp[target].first.size();
        
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */