//Link: https://leetcode.com/problems/get-the-maximum-score/
//Make sure you don't take mod between the computation use long long and take it at the end of the whole computation

#define ll long long
const int nx = 1e5 + 100;
ll dp[nx][2];
ll mod;
class Solution {
public:
    unordered_map<ll, ll> first, second;
    vector<int> v1, v2;
    int n, m;
    
    ll func(int ind, int ar) {
        if(ar == 0 and ind == n) return 0;
        if(ar == 1 and ind == m) return 0;
        if(dp[ind][ar] != -1) return dp[ind][ar];
        
        ll ans = (func(ind + 1, ar) + (ar ? v2[ind] : v1[ind]));
        
        if(ar == 0 and second.count(v1[ind])) {
            int index = second[v1[ind]];
            ans = max(ans, func(index + 1, 1) + v1[ind]);
        } else if(ar == 1 and first.count(v2[ind])) {
            int index = first[v2[ind]];
            ans = max(ans, func(index + 1, 0) + v2[ind]);
        }
        
        return dp[ind][ar] = ans;
    }
    
    int maxSum(vector<int>& v1, vector<int>& v2) {
        memset(dp, -1, sizeof dp);        
        mod = 1e9 + 7;
        this->n = v1.size();
        this->m = v2.size();
        this->v1 = v1;
        this->v2 = v2;
        
        for(int i = 0; i < n; ++i) first[v1[i]] = i;
        for(int i = 0; i < m; ++i) second[v2[i]] = i;
        
        return max(func(0, 0), func(0, 1)) % mod;
    }
};