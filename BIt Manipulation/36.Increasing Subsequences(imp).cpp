//Link: https://leetcode.com/problems/increasing-subsequences/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> seq, nums;
    
    void fun(int ind) {
        if(seq.size() > 1) ans.push_back(seq);
        if(ind == nums.size()) return;
        
        unordered_set<int> used;
        
        for(int i = ind; i < nums.size(); ++i) {
            if((seq.empty() or nums[i] >= seq.back()) and !used.count(nums[i])) {
                seq.push_back(nums[i]);
                fun(i + 1);
                seq.pop_back();
                used.insert(nums[i]);
            }
        } 
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->nums = nums;
        fun(0);
        return ans;
    }
};