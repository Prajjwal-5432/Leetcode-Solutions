//Link: https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution {
public:
    vector<vector<int>> graf;
    vector<set<pair<int, int>>> dag;
    vector<int> sum, sub;
    
    int dfs1(int v, int par) {
        for(auto x: graf[v]) {
            if(x == par) continue;
            sub[v] += dfs1(x, v);
        }
        
        for(auto x: graf[v]) {
            if(x == par) continue;
            sum[v] += sum[x];
            dag[v].insert({x, sum[x] + sub[x]});
        }
        sum[v] += sub[v];
        sub[v] += 1;
        
        return sub[v];
    }
    
    void dfs2(int v, int par) {
        if(par != -1) {
            auto it = dag[par].lower_bound({v, -1});
            int val = it->second;
            sum[v] += (sum[par] - val) + (sub[0] - sub[v]);
        }
        for(auto [x, y]: dag[v]) dfs2(x, v);
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graf.resize(n);
        dag.resize(n);
        sum.resize(n);
        sub.resize(n);
        
        for(auto x: edges) {
            graf[x[0]].push_back(x[1]);
            graf[x[1]].push_back(x[0]);
        }
        
        dfs1(0, -1);
        dfs2(0, -1);
        
        return sum;
    }
};