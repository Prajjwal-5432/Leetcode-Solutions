//Link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    vector<vector<int>> points;
    vector<array<long, 2>> rng;
    vector<long> dp;
    int n;
    
    long dfs(long ind) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        long ans = INT_MAX;
        for(int i = 0; i < points[ind].size(); ++i) {
            long lef = rng[points[ind][i]][0];
            long rig = rng[points[ind][i]][1];
            
            if(lef < rig)
                ans = min(ans, 1 + dfs(rig));
        }
        return dp[ind] = ans;
    }
    
    int minTaps(int n, vector<int>& v) {
        points.resize(n + 1);
        rng.resize(n + 1);
        this->n = n;
        
        for(int i = 0; i < n + 1; ++i) {
            int lef = max(0, i - v[i]);
            int rig = min(i + v[i], n);
            
            for(int j = lef; j < rig; ++j) {
                points[j].push_back(i);
            }
            rng[i] = {lef, rig};
        }
        
        dp.resize(n * 10, -1);
        long ans = dfs(0);
        
        return ans == INT_MAX ? -1 : ans;
        return 0;
    }
};