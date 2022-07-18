//Link: https://leetcode.com/problems/domino-and-tromino-tiling/

long long dp[1111];
const int mod = 1e9 + 7;
class Solution {
public:
    int n;
    void add(long long &a, long long b) {
        a += b;
        if(a >= mod) a -= mod;
    }
    long long dfs(int ind) {
        if(ind == n) return 1;
        if(ind > n) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        long long ans = dfs(ind + 1);
        add(ans, dfs(ind + 2));
        for(int i = ind + 2; i < n; ++i) {
            add(ans, dfs(i + 1));
            add(ans, dfs(i + 1));
        }
        return dp[ind] = ans;
    }
    int numTilings(int n) {
        this->n = n;
        memset(dp, -1, sizeof dp);
        return dfs(0);
    }
};