//Link: https://leetcode.com/problems/parallel-courses-ii/

int dp[(1LL << 16) + 123];
class Solution {
public:
    vector<int> preq, deg, cmask;
    vector<vector<int>> graf;
    
    int dfs(int mask, int k) {
        if(mask == 0) return 0;
        if(dp[mask] != -1) return dp[mask];
        
        int ans = 1235;
        for(int submask = mask; submask; submask = mask & (submask - 1)) {
            int bits = __builtin_popcount(submask);
            if(bits <= k and (mask & ~cmask[submask]) == mask) {
                ans = min(ans, 1 + dfs(mask ^ submask, k));
            }
        }
        
        return dp[mask] = ans;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        preq.resize(n + 1, 0);
        graf.resize(n + 1);
        deg.resize(n + 1, 0);
        cmask.resize(1 << (n + 1), 0);
        memset(dp, -1, sizeof dp);
        
        for(auto x: relations) {
            graf[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }
        
        queue<int> q;
        for(int i = 1; i <= n; ++i) {
            if(deg[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            
            for(auto x: graf[v]) {
                deg[x]--;
                preq[x] |= preq[v];
                preq[x] |= (1 << v);
                if(deg[x] == 0) q.push(x);
            }
        }
        
        for(int mask = 0; mask < (1 << n); ++mask) {
            for(int bit = 0, val = mask; val; val >>= 1, ++bit) {
                if(val & 1) {
                    cmask[mask << 1] |= preq[bit + 1];
                }
            }
        }
        
        return dfs(((1 << n) - 1) << 1, k);
    }
};