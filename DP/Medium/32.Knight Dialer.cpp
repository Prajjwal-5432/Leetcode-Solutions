//Link: https://leetcode.com/problems/knight-dialer/

#define ll long long

const int nx = 5e3 + 10;
ll dp[nx][4][3];
ll mod;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, 1, -1};

class Solution {
public:   
    ll func(int n, int i, int j) {
        if(n == 0) return 1;
        if(dp[n][i][j] != -1) return dp[n][i][j];
        
        ll ans = 0;
        for(int t = 0; t < 8; ++t) {
            int x = i + dx[t];
            int y = j + dy[t];
            
            if(x == 3 and y == 0) continue;
            if(x == 3 and y == 2) continue;
            
            if(min(x, y) >= 0 and x < 4 and y < 3) {
                ans = (ans + func(n - 1, x, y)) % mod;
            }
        }
        
        return dp[n][i][j] = ans;
    }
    
    int knightDialer(int n) {
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
        
        ll ans = 0;
        for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) {
            ans = (ans + func(n - 1, i, j)) % mod;
        }
        ans = (ans + func(n - 1, 3, 1)) % mod;
        
        return ans;
    }
};