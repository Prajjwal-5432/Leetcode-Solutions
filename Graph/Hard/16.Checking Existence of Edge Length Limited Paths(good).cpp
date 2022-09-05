//Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

class Solution {
public:
    vector<int> par, lev;
    int fset(int v) {
        return v == par[v] ? v : par[v] = fset(par[v]);
    }
    void uset(int u, int v) {
        u = fset(u), v = fset(v);
        if(u != v) {
            if(lev[u] < lev[v]) swap(u, v);
            par[v] = u;
            lev[u] += lev[v];
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edg, vector<vector<int>>& q) {
        par.resize(n);
        lev.resize(n, 1);
        iota(par.begin(), par.end(), 0);
        
        vector<bool> res(q.size(), 0);
        for(int i = 0; i < q.size(); ++i) q[i].push_back(i);
        
        sort(q.begin(), q.end(), [&](auto &x, auto &y) { return x[2] < y[2]; });
        sort(edg.begin(), edg.end(), [&](auto &x, auto &y) { return x[2] < y[2]; });
        
        int i = 0;
        for(auto x: q) {
            int u = x[0], v = x[1], lim = x[2], id = x[3];
            for(; i < edg.size() and edg[i][2] < lim; ++i) uset(edg[i][0], edg[i][1]);
            
            res[id] = fset(u) == fset(v);
        }
        
        return res;
    }
};