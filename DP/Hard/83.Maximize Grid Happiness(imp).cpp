//Link: https://leetcode.com/problems/maximize-grid-happiness/

int dp[6][1L << 10][7][7];

class Solution {
public:
    int n, m;
    int getMaxGridHappiness(int M, int N, int introvertsCount, int extrovertsCount) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);
        
        n = M, m = N;
        memset(dp, -1, sizeof dp); 
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }
    
    int dfs(int ind, int mask, int ic, int ec) {
        if(ind == n) return 0;
        if(dp[ind][mask][ic][ec] != -1) return dp[ind][mask][ic][ec];
        
        int ans = 0;
        for(int m1 = 0; m1 < (1 << m); ++m1) {
            for(int m2 = 0; m2 < (1 << m); ++m2) {
                if((m1 & m2) == 0 and cnt(m1) <= ic and cnt(m2) <= ec) {
                    int nmask = (introMask(m1) | extroMask(m2));
                    ans = max(ans, getScore(mask, nmask) + dfs(ind + 1, nmask, ic - cnt(m1), ec - cnt(m2)));
                }
            }
        }
        
        return dp[ind][mask][ic][ec] = ans;
    }
    
    int introMask(int mask) {
        int val = 0;
        for(int i = 0; mask; mask >>= 1, i += 2) {
            if(mask & 1) val |= (1 << i);
        }
        return val;
    }
    int extroMask(int mask) {
        int val = 0;
        for(int i = 0; mask; mask >>= 1, i += 2) {
            if(mask & 1) val |= (1 << (i + 1));
        }
        return val;
    }
    int cnt(int mask) {
        return __builtin_popcount(mask);
    }
    
    int getScore(int mask1, int mask2) {
        int ar[2][m];
        for(int i = m - 1; ~i; --i) {
            ar[0][i] = (mask1 & 3);
            ar[1][i] = (mask2 & 3);
            mask1 /= 4, mask2 /= 4;
        }
        
        int tot = 0;
        for(int i = 0; i < m; ++i) {
            if(ar[1][i] == 1) {
                tot += 120;
                if(ar[0][i] != 0) tot -= 30;
                if(i + 1 < m and ar[1][i + 1] != 0) tot -= 30;
                if(i - 1 >= 0 and ar[1][i - 1] != 0) tot -= 30;
            } else if(ar[1][i] == 2) {
                tot += 40;
                if(ar[0][i] != 0) tot += 20;
                if(i + 1 < m and ar[1][i + 1] != 0) tot += 20;
                if(i - 1 >= 0 and ar[1][i - 1] != 0) tot += 20;
            }
            
            if(ar[0][i] == 1 and ar[1][i] != 0) tot -= 30;
            if(ar[0][i] == 2 and ar[1][i] != 0) tot += 20;
        }
        
        return tot;
    }
};