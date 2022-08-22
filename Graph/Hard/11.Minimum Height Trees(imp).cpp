//Link: https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int> ({0});
        vector<vector<int>> graf(n);
        vector<int> deg(n, 0);
        
        for(auto x: edges) {
            int u = x[0], v = x[1];
            graf[u].push_back(v);
            graf[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(deg[i] == 1) q.push(i);
        }
        
        vector<int> res;
        while(!q.empty()) {
            res.clear();
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                int v = q.front();
                q.pop();
                res.push_back(v);
                for(auto x: graf[v]) {
                    deg[x]--;
                    if(deg[x] == 1) q.push(x);
                }
            }
        }
        
        return res;
    }
};