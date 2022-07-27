//Link: https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    vector<int> nxt, dp;
    int dfs(int ind) {
        if(ind >= nxt.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        return dp[ind] = max(dfs(ind + 1), 1 + dfs(nxt[ind]));
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        
        int n = v.size();
        
        nxt.resize(n, n);
        dp.resize(n + 10, -1);
        
        for(int i = 0; i < n; ++i) {
            nxt[i] = lower_bound(v.begin(), v.end(), vector<int> ({v[i][1], -600000})) - v.begin();
        }
        
        return n - dfs(0);
    }
};