//Link: https://leetcode.com/problems/count-the-number-of-ideal-arrays/

#define ll long long
const int nx = 1e4 + 100;
ll length[nx][21];
ll dp[nx][21];
ll mod;
class Solution {
public:   
    void countLength() {
        for(int i = 1; i < nx; ++i) {
            length[i][1] = 1;
            for(int j = i + i; j < nx; j += i) {
                for(int k = 0; k < 20; ++k) length[j][k + 1] += length[i][k];
            }
        }
    }
    ll Unique(int len, int mx) {
        if(len == 0) return mx == 0;
        if(mx == 0) return 0;
        if(dp[len][mx] != -1) return dp[len][mx];
        return dp[len][mx] = (Unique(len - 1, mx - 1) + Unique(len - 1, mx)) % mod;
    }
    int idealArrays(int n, int maxValue) {
        memset(dp, -1, sizeof dp);
        memset(length, 0, sizeof length);
        mod = 1e9 + 7;
        
        countLength();
        
        ll ans = 0;
        for(int i = maxValue; i >= 1; --i) {
            for(int j = 1; j < 21; ++j) {
                ans = (ans + (Unique(n, j) * length[i][j]) % mod) % mod;
            }
        }
        
        return ans % mod;
    }
};