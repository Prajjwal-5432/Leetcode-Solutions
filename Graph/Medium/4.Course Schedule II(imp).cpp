//Link: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<vector<int>> graf;
    vector<int> deg;
    vector<int> findOrder(int n, vector<vector<int>>& e) {
        graf.resize(n);
        deg.resize(n);
        
        for(auto x: e) {
            graf[x[1]].push_back(x[0]);
            deg[x[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(deg[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        int edges = e.size();
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            topo.push_back(v);
            
            for(auto x: graf[v]) {
                deg[x]--;
                edges--;
                if(deg[x] == 0) q.push(x);
            }
        }
        
        if(edges != 0) return {};
        return topo;
    }
};