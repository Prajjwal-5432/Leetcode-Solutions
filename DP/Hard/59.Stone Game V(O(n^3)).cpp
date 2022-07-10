//Link: https://leetcode.com/problems/stone-game-v/

long long dp[555][555];
class Solution {
public:
    long long dfs(int i, int j, vector<int> &s) {
        if(i == j or i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        long long tot = accumulate(s.begin() + i, s.begin() + j + 1, 0LL);
        long long ans = 0, sum = 0;
        for(int k = i; k < j; ++k) {
            sum += s[k];
            if(sum * 2 > tot) {
                ans = max(ans, tot - sum + dfs(k + 1, j, s));
            } else if(sum * 2 < tot) {
                ans = max(ans, sum + dfs(i, k, s));
            } else if(sum * 2 == tot) {
                ans = max(ans, sum + max(dfs(i, k, s), dfs(k + 1, j, s)));
            }
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& s) {
        memset(dp, -1, sizeof dp);
        return dfs(0, s.size() - 1, s);
    }
};