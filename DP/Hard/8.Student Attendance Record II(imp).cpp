//Link: https://leetcode.com/problems/student-attendance-record-ii/

#define ll long long
const int nx = 1e5 + 10;
ll dp[nx][2][3];
ll mod;

class Solution {
public:
    ll func(int ind, int absent, int late, int n) {
        if(ind == n) return 1;
        if(dp[ind][absent][late] != -1) return dp[ind][absent][late];
        
        ll ans = func(ind + 1, absent, 0, n);
        if(absent == 0) {
            ans = (ans + func(ind + 1, 1, 0, n)) % mod;
        }
        if(late < 2) {
            ans = (ans + func(ind + 1, absent, late + 1, n)) % mod;
        }
        
        return dp[ind][absent][late] = ans;
    }
    int checkRecord(int n) {
        mod = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        
        ll ans = func(1, 0, 0, n);
        ans = (ans + func(1, 1, 0, n)) % mod;
        ans = (ans + func(1, 0, 1, n)) % mod;
        
        return ans;
    }
};