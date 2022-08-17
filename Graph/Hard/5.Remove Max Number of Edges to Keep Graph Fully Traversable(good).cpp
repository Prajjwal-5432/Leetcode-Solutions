//Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

struct DSU {
    vector<int> par, lev;
    
    DSU(int n) {
        par.resize(n);
        lev.resize(n, 1);
        iota(par.begin(), par.end(), 0);
    }
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
    int siz(int v) {
        return lev[fset(v)];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU ac(n + 1), bc(n + 1); 
        
        int deletions = 0;
        for(auto x: edges) {
            int type = x[0], u = x[1], v = x[2];
            if(type == 3) {
                if(ac.fset(u) == ac.fset(v)) {
                    deletions++;
                    continue;
                }
                ac.uset(u, v);
                bc.uset(u, v);
            }
        }
        
        for(auto x: edges) {
            int type = x[0], u = x[1], v = x[2];
            
            if(type == 1) {
                if(ac.fset(u) == ac.fset(v)) deletions++;
                else ac.uset(u, v);
            } else if(type == 2) {
                if(bc.fset(u) == bc.fset(v)) deletions++;
                else bc.uset(u, v);
            }
        }
        
        if(ac.siz(1) != n or bc.siz(1) != n) return -1;
        return deletions;
    }
};