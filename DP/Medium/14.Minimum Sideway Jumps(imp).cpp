//Link: https://leetcode.com/problems/minimum-sideway-jumps/

const static int nx = 5e5 + 100;
long dp[4][2][nx];
vector<int> ob;
int n;

class Solution {
public:
    long func(int lane, int side, int ind) {
        if(ind == n) return 0;
        if(ob[ind] == lane) return INT_MAX / 2;
        if(dp[lane][side][ind] != -1) return dp[lane][side][ind];
        
        long ans = INT_MAX / 2;
        if(side == 1) {
            for(int i = 1; i < 4; ++i) {
                if(lane != i) 
                    ans = min(ans, 1 + func(i, 0, ind));
            }
        }
        
        ans = min(ans, func(lane, 1, ind + 1));
        
        return dp[lane][side][ind] = ans;
    }
    
    int minSideJumps(vector<int>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        n = a.size();
        memset(dp, -1, sizeof dp);
        ob = a;
        
        return func(2, 1, 0);
    }
};