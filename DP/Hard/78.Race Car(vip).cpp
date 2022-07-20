//Link: https://leetcode.com/problems/race-car/
//Refer: https://leetcode.com/problems/race-car/discuss/246138/java-DP-solution-heavily-commented.

class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, 0);
        
        for(int i = 1; i <= target; ++i) {
            
            int rightSteps = 0;
            int rightPosition = 0;
            while(rightPosition < i) {
                rightSteps++;
                rightPosition = (1 << rightSteps) - 1;
            }
            
            if(rightPosition == i) {
                dp[i] = rightSteps;
                continue;
            }
            
            dp[i] = rightSteps + 1 + dp[rightPosition - i];
            
            int leftSteps = rightSteps - 1;
            int leftPosition = (1 << leftSteps) - 1;
            
            for(int j = 0; j < leftSteps; ++j) {
                int cur = leftPosition - (1 << j) + 1;
                dp[i] = min(dp[i], leftSteps + 1 + j + 1 + dp[i - cur]);
            }
        }
        
        return dp[target];
    }
};