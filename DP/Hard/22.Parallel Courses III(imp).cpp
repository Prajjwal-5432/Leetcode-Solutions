//Link: https://leetcode.com/problems/parallel-courses-iii/

class Solution {
public:
    vector<vector<int>> graf;
    vector<int> dist, time;
    
    int dfs(int v) {
        if(dist[v]) return dist[v];
        
        int ans = 0;
        for(auto u: graf[v]) ans = max(ans, dfs(u));
        
        return dist[v] = ans + time[v];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        this->time = time;
        graf.resize(n);
        dist.resize(n);
        
        for(auto x: relations) {
            graf[x[0] - 1].push_back(x[1] - 1);
        }
        
        for(int i = 0; i < n; ++i) dfs(i);
        
        return *max_element(dist.begin(), dist.end());
    }
};