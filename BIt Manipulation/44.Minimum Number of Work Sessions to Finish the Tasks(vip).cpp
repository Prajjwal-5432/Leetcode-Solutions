//Link: https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
//Refer: https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/discuss/1436811/C%2B%2BJavaPython-From-Straightforward-to-Optimized-Bitmask-DP-O(2n-*-n)-Clean-and-Concise

class Solution {
public:
    int n, sessionTime;
    vector<int> tasks;
    int dp[1 << 15][16];
    
    int func(int mask, int leftTime) {
        if(mask == 0) return 0;
        if(dp[mask][leftTime] != -1) return dp[mask][leftTime];
        
        int ans = n;
        
        for(int i = 0; i < n; ++i) {
            if((mask >> i) & 1) {
                int newMask = mask & ~(1 << i);
                
                if(tasks[i] <= leftTime) {
                    ans = min(ans, func(newMask, leftTime - tasks[i]));
                } else {
                    ans = min(ans, func(newMask, sessionTime - tasks[i]) + 1);
                }
            }
        }
        
        return dp[mask][leftTime] = ans;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size();
        sort(tasks.begin(), tasks.end());
        this->sessionTime = sessionTime;
        this->tasks = tasks;
        memset(dp, -1, sizeof(dp));
        
        return func((1 << n) - 1, 0);
    }
};