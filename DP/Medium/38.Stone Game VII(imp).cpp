//Link: https://leetcode.com/problems/stone-game-vii/

int dp[1111][1111][2];
int pre[1111];

class Solution {
public:
    int dfs(int i, int j, int turn, vector<int> &s) {
        if(i == j or i > j) return 0;
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        
        int ith = pre[j] - pre[i];
        int jth = pre[j - 1] - pre[i - 1];
        int ans = (turn) ? 0 : INT_MAX / 2;
        if(turn) {
            ans = max(ans, ith + dfs(i + 1, j, turn ^ 1, s));
            ans = max(ans, jth + dfs(i, j - 1, turn ^ 1, s));
        } else {
            ans = min(ans, -ith + dfs(i + 1, j, turn ^ 1, s));
            ans = min(ans, -jth + dfs(i, j - 1, turn ^ 1, s));
        }
        return dp[i][j][turn] = ans;
    }
    int stoneGameVII(vector<int>& s) {
        memset(dp, -1, sizeof dp);
        memset(pre, 0, sizeof pre);
        
        for(int i = 0; i < s.size(); ++i) 
            pre[i + 1] = pre[i] + s[i];
        
        return dfs(1, s.size(), 1, s);
    }
};