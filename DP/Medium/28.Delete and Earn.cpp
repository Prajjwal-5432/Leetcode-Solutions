//Link: https://leetcode.com/problems/delete-and-earn/

#define ll long long

const int nx = 2e4 + 100;
ll dp[nx];

class Solution {
public:
    vector<pair<int, int>> v;
    
    ll func(int ind) {
        if(ind >= v.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        ll ans = v[ind].first * v[ind].second;

        if(ind + 1 < v.size() and v[ind + 1].first != v[ind].first + 1) ans += func(ind + 1);
        else if(ind + 2 < v.size()) ans += func(ind + 2);
        
        ans = max(ans, func(ind + 1));
        
        return dp[ind] = ans;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for(auto x: nums) mp[x]++;
        
        v.assign(mp.begin(), mp.end());
        
        memset(dp, -1, sizeof dp);
        
        return func(0);
    }
};