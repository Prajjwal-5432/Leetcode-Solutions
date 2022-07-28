//Link: https://leetcode.com/problems/tallest-billboard/

class Solution {
public:
    int dp[22][11111], mx[22][11111];
    
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        dp[0][5000] = 1;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 10001; ++j) {
                if(j - rods[i] >= 0 and dp[i][j - rods[i]]) {
                    dp[i + 1][j] = 1;
                    mx[i + 1][j] = max(mx[i + 1][j], mx[i][j - rods[i]] + rods[i]);
                }
                if(j + rods[i] >= 0 and dp[i][j + rods[i]]) {
                    dp[i + 1][j] = 1;
                    mx[i + 1][j] = max(mx[i + 1][j], mx[i][j + rods[i]]);
                }
                if(j - rods[i] >= 0 and dp[i][j]) {
                    dp[i + 1][j] = 1;
                    mx[i + 1][j] = max(mx[i + 1][j], mx[i][j]);
                }
            }
        }
        
        return mx[n][5000];
    }
};