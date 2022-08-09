//Link: https://leetcode.com/problems/the-time-when-the-network-becomes-idle/

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> graf(n);
        
        for(auto x: edges) {
            graf[x[0]].push_back(x[1]);
            graf[x[1]].push_back(x[0]);
        }
        
        vector<int> dis(n, n), vis(n);
        vis[0] = 1;
        dis[0] = 0;
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            
            for(auto x: graf[v]) {
                if(!vis[x]) {
                    vis[x] = 1;
                    dis[x] = dis[v] + 1;
                    q.push(x);
                }
            }
        }
        
        int mx = 0;
        for(int i = 1; i < n; ++i) {
            int tot = dis[i] * 2;
            int extra = (tot - 1) / patience[i];
            mx = max(mx, tot + extra * patience[i]);
        }
        
        return mx + 1;
    }
};