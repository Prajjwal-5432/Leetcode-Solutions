//Link: https://leetcode.com/problems/minimum-cost-for-tickets/

const int nx = 400;
int dp[nx];

class Solution {
public:
    vector<int> costs, days;
    int n;
    
    int func(int ind) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int ans = INT_MAX / 2;
        
        ans = min(ans, costs[0] + func(ind + 1));
        
        int index;
        for(int i = ind; i < days.size(); ++i) {
            if(days[i] >= days[ind] + 7) {
                index = i;
                break;
            }
        }
        ans = min(ans, costs[1] + func(index));
        
        for(int i = ind; i < days.size(); ++i) {
            if(days[i] >= days[ind] + 30) {
                index = i;
                break;
            }
        }
        ans = min(ans, costs[2] + func(index));
        
        return dp[ind] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof dp);        
        n = days.size();
        
        this->days = days;
        this->days.push_back(367);
        this->costs = costs;
        
        return func(0);
    }
};