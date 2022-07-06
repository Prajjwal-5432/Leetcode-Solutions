//Link: https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/

int dp[1111][1111];
class Solution {
public:
    string floor;
    int n;
    vector<int> pre;
    int dfs(int ind, int cpt, int len) {
        if(ind >= floor.size()) return 0;
        if(dp[ind][cpt] != -1) return dp[ind][cpt];
        
        int ans = dfs(ind + 1, cpt, len);
        if(cpt > 0 and floor[ind] == '1')
            ans = max(ans, pre[min(ind + len, n)] - pre[ind] + dfs(ind + len, cpt - 1, len));
        
        return dp[ind][cpt] = ans;
    }
    int minimumWhiteTiles(string floor, int cpt, int len) {
        memset(dp, -1, sizeof dp);
        this->floor = floor;
        n = floor.size();
        
        pre.resize(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (floor[i] == '1');
        }
        
        return pre[n] - dfs(0, cpt, len);
    }
};