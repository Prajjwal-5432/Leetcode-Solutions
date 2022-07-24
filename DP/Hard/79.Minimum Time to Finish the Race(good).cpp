//Link: https://leetcode.com/problems/minimum-time-to-finish-the-race/

class Solution {
public:
    vector<long> laps;
    int maxLaps;
    long dp[1111];
    
    long dfs(int leftLaps, int changeTime) {
        if(leftLaps == 0)
            return -changeTime;
        
        if(dp[leftLaps] != -1) return dp[leftLaps];
        
        long ans = INT_MAX / 2;
        for(int i = 1; i <= min(leftLaps, maxLaps); ++i) {
            ans = min(ans, laps[i] + changeTime + dfs(leftLaps - i, changeTime));
        }
        
        return dp[leftLaps] = ans;
    }
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size();
        
        laps.resize(1111, INT_MAX / 2);
        for(auto x: tires) {
            long prev = 0, nval = 1;
            for(int i = 1; x[0] * nval <= x[0] + changeTime; ++i) {
                laps[i] = min(laps[i], prev += (nval * x[0]));
                maxLaps = max(maxLaps, i);
                nval *= x[1];
            }
        }
        
        memset(dp, -1, sizeof dp);
        
        return dfs(numLaps, changeTime);
    }
};