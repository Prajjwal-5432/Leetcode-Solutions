//Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> arr;
    vector<bool> vis;
    
    void dfs(int v) {
        if(vis[v]) return;
        
        vis[v] = 1;
        arr.push_back(v);
        
        for(auto u: graph[v]) dfs(u);
    }
    
    vector<int> restoreArray(vector<vector<int>>& adj) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        unordered_map<int, int> cnt, mp, rev;
        
        for(auto x: adj) 
            cnt[x[0]]++, cnt[x[1]]++;
        
        int i = 0, start;
        for(auto [x, y]: cnt) {
            if(y == 1) start = x;
            mp[x] = i, rev[i++] = x;
        }
        
        int n = adj.size() + 1;
        graph.resize(n);
        vis.resize(n, 0);
        
        for(auto x: adj) {
            graph[mp[x[0]]].push_back(mp[x[1]]);
            graph[mp[x[1]]].push_back(mp[x[0]]);
        }
        dfs(mp[start]);
        
        for(auto &x: arr) x = rev[x];
        
        return arr;
    }
};