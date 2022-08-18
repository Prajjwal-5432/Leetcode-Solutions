//Link: https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int n) {
        vector<vector<pair<int, int>>> graf(n);
        vector<int> vis(n, 0);
        
        for(auto x: edges) {
            int u = x[0], v = x[1], cnt = x[2];
            graf[u].push_back({v, cnt});
            graf[v].push_back({u, cnt});
        }
        
        priority_queue<pair<int, int>> pq;
        pq.push({M, 0});
        int ans = 0;
        while(!pq.empty()) {
            int v = pq.top().second, moves = pq.top().first;
            pq.pop();
            
            if(!vis[v]) {
                vis[v] = moves;
                ans++;
                for(auto [x, y]: graf[v]) {
                    int left = moves - y - 1;
                    if(!vis[x] and left >= 0) pq.push({left, x});
                }
            }
        }
        
        for(auto x: edges) {
            int u = x[0], v = x[1], cnt = x[2];
            int tot = vis[u] + vis[v];
            ans += min(tot, cnt);
        }
        
        return ans;
    }
};