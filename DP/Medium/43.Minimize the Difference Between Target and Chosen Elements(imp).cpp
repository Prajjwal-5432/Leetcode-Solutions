//Link: https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/

class Solution {
public:
    int dp[77][5000];
    int dfs(vector<set<int>> &v, int i, int sum, int target) {
        if(i >= v.size()) return abs(sum - target);
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int ans = INT_MAX;
        for(auto x: v[i]) {
            ans = min(ans, dfs(v, i + 1, sum + x, target));
            if(sum + x > target) break;
        }
        
        return dp[i][sum] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp, -1, sizeof dp);
        
        vector<set<int>> v;
        for(auto x: mat) v.push_back(set<int> (x.begin(), x.end()));
        
        return dfs(v, 0, 0, target);
    }
};