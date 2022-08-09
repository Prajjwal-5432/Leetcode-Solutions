//Link: https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; ++i) {
            if(color[i] == -1) {
                color[i] = 1;
                
                queue<int> q;
                q.push(i);

                while(!q.empty()) {
                    int v = q.front();
                    q.pop();

                    for(auto x: graph[v]) {
                        if(color[x] == -1) {
                            q.push(x);
                            color[x] = 1 - color[v];
                        } else if(color[x] == color[v]) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};