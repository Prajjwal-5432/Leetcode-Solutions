https://leetcode.com/problems/sort-integers-by-the-power-value/

const int nx = 5e6 + 100;
int dp[nx];

class Solution {
public:
    Solution() {
        memset(dp, -1, sizeof dp);
    }
    int func(int num) {
        if(num == 1) return 0;
        if(dp[num] != -1) return dp[num];
        
        int ans = 1;
        if(num & 1) ans += func(num * 3 + 1);
        else ans += func(num / 2);
        
        return dp[num] = ans;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;
        for(int i = lo; i < hi + 1; ++i) {
            v.push_back({func(i), i});
        }
        
        sort(v.begin(), v.end(), [&](auto x, auto y) {
            return x.first != y.first ? x.first < y.first : x.second < y.second;
        });
        
        return v[k - 1].second;
    }
};