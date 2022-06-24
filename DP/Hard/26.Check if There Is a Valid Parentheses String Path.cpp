//Link: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/

int dp[111][111][222];

class Solution {
public:
    vector<vector<char>> grid;
    int n, m;
    
    bool dfs(int i, int j, int open) {
        if(i == n - 1 and j == m - 1) return open == 0;
        if(dp[i][j][open] != -1) return dp[i][j][open];
        
        bool ans = 0;
        if(i + 1 < n) {
            if(grid[i + 1][j] == '(') ans |= dfs(i + 1, j, open + 1);
            else if(open > 0) ans |= dfs(i + 1, j, open - 1);
        }
        if(j + 1 < m) {
            if(grid[i][j + 1] == '(') ans |= dfs(i, j + 1, open + 1);
            else if(open > 0) ans |= dfs(i, j + 1, open - 1);
        }
        
        return dp[i][j][open] = ans;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0] == ')') return 0;
        
        memset(dp, -1, sizeof dp);
        this->grid = grid;
        this->n = grid.size();
        this->m = grid[0].size();
        
        int ans = 0;
        if(n > 1) ans |= dfs(1, 0, 1 + (grid[1][0] == '(' ? 1 : -1));
        if(m > 1) ans |= dfs(0, 1, 1 + (grid[0][1] == '(' ? 1 : -1));
        
        return ans;
    }
};