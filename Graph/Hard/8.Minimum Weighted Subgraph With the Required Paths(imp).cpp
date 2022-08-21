//Link: https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/

#define ll long long
class Solution {
public:
    void calc(int src, vector<ll> &dis, vector<vector<pair<ll, ll>>> &graf) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if(d > dis[v]) continue;
            for(auto [x, y]: graf[v]) {
                if(dis[v] + y < dis[x]) {
                    dis[x] = dis[v] + y;
                    pq.push({dis[x], x});
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<ll, ll>>> graf, rev;
        graf.resize(n);
        rev.resize(n);
        
        for(auto x: edges) {
            graf[x[0]].push_back({x[1], x[2]});
            rev[x[1]].push_back({x[0], x[2]});
        }
        
        vector<ll> da(n, LONG_MAX), db(n, LONG_MAX), dd(n, LONG_MAX);
        da[src1] = db[src2] = dd[dest] = 0;
        calc(src1, da, graf);
        calc(src2, db, graf);
        calc(dest, dd, rev);
        
        ll ans = LONG_MAX;
        for(int i = 0; i < n; ++i) {
            if(da[i] == LONG_MAX or db[i] == LONG_MAX or dd[i] == LONG_MAX) continue;
            ans = min(ans, da[i] + db[i] + dd[i]);
        } 
        
        return ans == LONG_MAX ? -1 : ans;
    }
};
