//Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/

class Solution {
public:
    int vis[1 << 12][12];
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int all = (1 << n) - 1;
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; ++i) {
            q.push({1 << i, i});
        }
        
        int steps = 0;
        
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                int mask = q.front().first;
                int node = q.front().second;
                
                q.pop();
                
                if(vis[mask][node]) continue;
                if(mask == all) return steps;
                
                vis[mask][node] = 1;
                for(auto x: graph[node]) {
                    q.push({mask | (1 << x), x});
                }
            }
            steps++;
        }
        
        return -1;
    }
};