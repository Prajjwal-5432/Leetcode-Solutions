//Link: https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/

#define ll long long

ll tot[13][1 << 13];
ll dp[13][1 << 13];

class Solution {
public:
    int size1, size2;
    
    ll dfs(int ind, int mask) {
        if(ind == size1) return mask ? INT_MAX : 0;
        if(dp[ind][mask] != -1) return dp[ind][mask];
        
        ll ans = INT_MAX;
        for(int submask = mask; submask; submask = (submask - 1) & mask) {
            ans = min(ans, tot[ind][submask] + dfs(ind + 1, mask ^ submask));
        }
        for(int bit = 0, val = mask; val; ++bit, val >>= 1) {
            ans = min(ans, tot[ind][1 << bit] + dfs(ind + 1, mask));
        }
        
        return dp[ind][mask] = ans;
    }
    
    int connectTwoGroups(vector<vector<int>>& cost) {
        memset(dp, -1, sizeof dp);
        memset(tot, 0, sizeof tot);
        
        size1 = cost.size(), size2 = cost[0].size();
        
        for(int i = 0; i < size1; ++i) {
            for(int mask = 0; mask < (1 << size2); ++mask) {
                for(int j = 0, val = mask; val; ++j, val >>= 1) {
                    if(val & 1) tot[i][mask] += cost[i][j];
                }
            }
        }
        
        return dfs(0, (1 << size2) - 1);
    }
};