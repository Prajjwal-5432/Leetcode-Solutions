//Link: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<int>> dp(target + 1, vector<int> (10, 0));
        vector<int> mx(target + 1, 0);
        
        for(int i = 1; i <= target; ++i) {
            for(int j = 1; j <= 9; ++j) {
                if(cost[j - 1] == i)
                    dp[i][j] = 1;
                else if(i > cost[j - 1] and mx[i - cost[j - 1]] > 0)
                    dp[i][j] = 1 + mx[i - cost[j - 1]];
                
                mx[i] = max(mx[i], dp[i][j]);
            }
        }
        
        if(mx[target] == 0) return "0";
        
        string res;
        
        while(target > 0) {
            for(int i = 9; i > 0; --i) {
                if(dp[target][i] == mx[target]) {
                    res += to_string(i);
                    target -= cost[i - 1];
                    break;
                }
            }
        }
        
        return res;
    }
};