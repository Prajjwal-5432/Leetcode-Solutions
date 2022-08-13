//Link: https://leetcode.com/problems/valid-arrangement-of-pairs/

struct hierholzer {
    vector<vector<int>> graf;
    vector<int> in, out, path;
    int n, edges;

    hierholzer(vector<vector<int>> &adj) {
        graf = adj;    
        n = graf.size();
        edges = 0;
    }
    
    vector<int> eulerPath() {
        prec();
        if(hasPath() == 0) return vector<int> ();
        
        dfs(startNode());
        reverse(path.begin(), path.end());
        
        if(path.size() != edges + 1) return vector<int> ();
        return path;
    }
    
    void dfs(int v) {
        while(out[v]) dfs(graf[v][--out[v]]);
        path.push_back(v);
    }
    
    void prec() {
        in = vector<int> (n, 0);
        out = vector<int> (n, 0);
        
        for(int i = 0; i < n; ++i) {
            for(auto &x: graf[i]) {
                out[i]++;
                in[x]++;
                edges++;
            }
        }
    }
    
    bool hasPath() {
        if(edges == 0) return 0;
        int startNodes = 0, endNodes = 0;
        for(int i = 0; i < n; ++i) {
            if(abs(out[i] - in[i]) > 1) return 0;
            else if(out[i] - in[i] == 1) startNodes++;
            else if(in[i] - out[i] == 1) endNodes++;
        }
        return (endNodes + startNodes == 0) or (endNodes == 1 and startNodes == 1);
    }
    
    int startNode() {
        int start = -1;
        for(int i = 0; i < n; ++i) {
            if(out[i] - in[i] == 1) return i;
            if(out[i] > 0) start = i;
        }
        return start;
    }
};
struct mhash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    uint64_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = 0;
        unordered_map<int, int, mhash> mp, rev;
        for(auto x: pairs) {
            int u = x[0], v = x[1];
            if(!mp.count(u)) mp[u] = n, rev[n] = u, n++;
            if(!mp.count(v)) mp[v] = n, rev[n] = v, n++;
        } 
        
        vector<vector<int>> graf(n);
        
        for(auto x: pairs) {
            graf[mp[x[0]]].push_back(mp[x[1]]);
        }
        
        hierholzer euler(graf);
        
        vector<int> path = euler.eulerPath();
        vector<vector<int>> res;
        
        for(int i = 0; i < path.size() - 1; ++i) {
            res.push_back({rev[path[i]], rev[path[i + 1]]});
        }
        
        return res;
    }
};