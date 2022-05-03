//Link: https://leetcode.com/problems/minimum-sideway-jumps/

class Solution {
public:
    int minSideJumps(vector<int>& a) {
        int dp[] = {INT_MAX / 2, 1, 0, 1};
        
        for(auto x: a) {
            dp[x] = dp[0];
            for(int j = 1; j < 4; ++j) {
                if(j != x)
                    dp[j] = min({dp[1] + (j != 1), dp[2] + (j != 2), dp[3] + (j != 3)});
            }
        }
        
        return min({dp[1], dp[2], dp[3]});
    }
};