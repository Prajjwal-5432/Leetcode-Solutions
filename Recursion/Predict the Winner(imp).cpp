//Link: https://leetcode.com/problems/predict-the-winner/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums, int player = 1) { 
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, 0)); 
        
        for(int gap = 0; gap < n; ++gap) {
            for(int i = 0, j = gap; j < n; ++j, ++i) {
                if(gap == 0) {
                    dp[i][j] = nums[i];
                } else if(gap == 1) {
                    dp[i][j] = max(nums[i], nums[j]);
                } else {
                    int val1 = nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                    int val2 = nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                    dp[i][j] = max(val1, val2);
                }
            }
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        return 2 * dp[0][n - 1] >= sum;
    }
};