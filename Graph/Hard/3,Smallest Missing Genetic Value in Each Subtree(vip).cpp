//Link: https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/

int vis[100099];
class Solution {
public:
    vector<int> nums;
    vector<vector<int>> graf;
    void dfs(int v) {
        if(vis[nums[v]] == 1) return;
        vis[nums[v]] = 1;
        for(auto x: graf[v]) dfs(x);
    }
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size();
        graf.resize(n);
        this->nums = nums;
        memset(vis, 0, sizeof vis);
        
        for(int i = 1; i < n; ++i) graf[parents[i]].push_back(i);
        
        vector<int> res(n, 1);
        
        int it = find(nums.begin(), nums.end(), 1) - nums.begin();
        int mn = 1;
        
        for(; it < n and it != -1; it = parents[it]) {
            dfs(it);
            while(vis[mn] == 1) mn++;
            res[it] = mn;
        }
        
        return res;
    }
};