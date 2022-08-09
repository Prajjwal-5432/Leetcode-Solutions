//Link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution {
public:
    int dp[44][44];
    
    int dfs(int i, int j, vector<int>& arr) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX / 2;
        for(int ind = i; ind < j; ++ind) {
            int lefmx = *max_element(arr.begin() + i, arr.begin() + ind + 1);
            int rigmx = *max_element(arr.begin() + ind + 1, arr.begin() + j + 1);
            ans = min(ans, lefmx * rigmx + dfs(i, ind, arr) + dfs(ind + 1, j, arr));
        }
        return dp[i][j] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp, -1, sizeof dp);
        return dfs(0, arr.size() - 1, arr);
    }
};