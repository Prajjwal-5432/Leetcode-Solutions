//Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

#define ll long long

class Solution {
public:
    vector<vector<int>> nums;
    vector<vector<ll>> dp;
    vector<int> next;
    int n;
    
    int nxt(int ind, vector<vector<int>> &events) {
        int lo = 0, hi = n - 1, best = n;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(events[mid][0] >= ind) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return best;
    }
    
    ll func(int ind, int k, vector<vector<int>> &events) {
        if(ind == n) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        ll ans = func(ind + 1, k, events);
        if(k) {
            ans = max(ans, events[ind][2] + func(next[ind], k - 1, events));
        }
        return dp[ind][k] = ans;
    }
    
    ll simple(vector<vector<int>> &events) {
        ll ans = 0;
        for(auto x: events) ans = max(ans, 1LL * x[2]);
        return ans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        this->n = events.size();
        
        if(k == 1) return simple(events);   
        
        sort(events.begin(), events.end(), [&](auto x, auto y) {
            return x[0] != y[0] ? x[0] < y[0] : x[1] < y[1];
        });
            
        dp.resize(n + 2, vector<ll> (k + 2, -1));
        next.resize(n);
        
        for(int i = 0; i < n; ++i) {
            next[i] = nxt(events[i][1] + 1, events);
        }
        return func(0, k, events);
    }
};