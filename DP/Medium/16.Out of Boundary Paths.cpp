//Link: https://leetcode.com/problems/out-of-boundary-paths/

const int nx = 55;
long long dp[nx][nx][nx];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    long long mod;
    int n, m;
    
    long long func(int x, int y, int moves) {
        if(x < 0 or x >= n or y < 0 or y >= m) return 1;
        if(dp[x][y][moves] != -1) return dp[x][y][moves];
        if(moves == 0) return 0;
        
        long long ans = 0;
        for(int t = 0; t < 4; ++t) {
            int i = x + dx[t];
            int j = y + dy[t];
            
            ans = (ans + func(i, j, moves - 1)) % mod;
        }
        
        return dp[x][y][moves] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
        this->n = m;
        this->m = n;
        
        return func(startRow, startColumn, maxMove);
    }
};