//Link: https://leetcode.com/problems/largest-1-bordered-square/

class Solution {
public:
    bool check(int x, int y, int n, int m) {
        return min(x, y) >= 1 and x <= n and y <= m;
    }
    
    int largest1BorderedSquare(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        
        for(int i = 1; i < n + 1; ++i) 
            for(int j = 1; j < m + 1; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i - 1][j - 1];
        
        int mx = 0, mn = min(n, m);
        for(int i = 1; i < n + 1; ++i) {
            for(int j = 1; j < m + 1; ++j) {
               if(a[i - 1][j - 1] == 0) continue;
               mx = max(mx, 1);
               for(int sq = mx; sq <= mn; ++sq) {
                    int x1 = i, y1 = j;
                    int x2 = i, y2 = j + sq - 1;
                    int x3 = i + sq - 1, y3 = j + sq - 1;
                    int x4 = i + sq - 1, y4 = j;
                    
                    bool flag = check(x1, y1, n, m);
                    flag &= check(x2, y2, n, m);
                    flag &= check(x3, y3, n, m);
                    flag &= check(x4, y4, n, m);
                    
                    if(flag) {
                        int l1 = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
                        int l2 = dp[x3][y3] - dp[x2 - 1][y3] - dp[x3][y2 - 1] + dp[x2 - 1][y2 - 1];
                        int l3 = dp[x3][y3] - dp[x4 - 1][y3] - dp[x3][y4 - 1] + dp[x4 - 1][y4 - 1];
                        int l4 = dp[x4][y4] - dp[x1 - 1][y4] - dp[x4][y1 - 1] + dp[x1 - 1][y1 - 1];
                        
                        if(l1 == l2 and l2 == l3 and l3 == l4 and l4 == sq) mx = max(mx, sq);
                    }
                }
            }
        }
        
        return mx * mx;
    }
};