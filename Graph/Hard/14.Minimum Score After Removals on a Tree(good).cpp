//Link: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/

class Solution {
public:
    vector<vector<int>> graf, edg, anc;
    vector<int> xorval, lev;
    int res = INT_MAX, n;
    int dfs1(int v, int par, int h, vector<int> &nums) {
        lev[v] = h;
        if(par != -1) edg.push_back({par, v});
        
        for(auto x: graf[v]) {
            if(x == par) continue;
            xorval[v] ^= dfs1(x, v, h + 1, nums);
        }
        
        anc[v][v] = 1;
        for(auto x: graf[v]) {
            if(x == par) continue;
            for(int i = 0; i < n; ++i) anc[v][i] |= anc[x][i];
        }
        xorval[v] ^= nums[v];
        return xorval[v];
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        
        graf.resize(n);
        xorval.resize(n);
        lev.resize(n);
        anc.resize(n, vector<int> (n, 0));
        
        for(auto x: edges) {
            graf[x[0]].push_back(x[1]);
            graf[x[1]].push_back(x[0]);
        }
        
        dfs1(0, -1, 0, nums);
        
        int res = INT_MAX;
        for(int i = 0; i < edg.size(); ++i) {
            for(int j = i + 1; j < edg.size(); ++j) {
                int u1 = edg[i][0], v1 = edg[i][1];
                int u2 = edg[j][0], v2 = edg[j][1];
                
                if(lev[u1] > lev[u2]) swap(u1, u2), swap(v1, v2);
                
                if(lev[u1] == lev[u2] or anc[v1][u2] == 0) {
                    int r1 = xorval[v1];
                    int r2 = xorval[v2];
                    int r3 = xorval[0] ^ r1 ^ r2;
                    res = min(res, max({r1, r2, r3}) - min({r1, r2, r3}));
                } else {
                    int r1 = xorval[v2];
                    int r2 = xorval[v1] ^ xorval[v2];
                    int r3 = xorval[0] ^ r1 ^ r2;
                    res = min(res, max({r1, r2, r3}) - min({r1, r2, r3}));     
                }
            }
        }
        
        return res;
    }
};