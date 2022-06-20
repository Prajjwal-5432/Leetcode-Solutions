//Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#define ll long long
class Solution {
public:
    vector<ll> dp, nxt;
    vector<array<ll, 3>> ar;
    
    ll dfs(int ind) {
        if(ind == ar.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        ll ans = dfs(ind + 1);
        ans = max(ans, ar[ind][2] + dfs(nxt[ind]));
        
        return dp[ind] = ans;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        dp.resize(n, -1);
        nxt.resize(n);
        ar.resize(n);
        
        for(int i = 0; i < n; ++i) ar[i] = {startTime[i], endTime[i], profit[i]};
        
        sort(ar.begin(), ar.end());
        sort(startTime.begin(), startTime.end());
        
        for(int i = 0; i < n; ++i) {
            nxt[i] = lower_bound(startTime.begin(), startTime.end(), ar[i][1]) - startTime.begin();
        }
        
        return dfs(0);
    }
};