//Link: https://leetcode.com/problems/closest-subsequence-sum/

#define ll long long

class Solution {
public:
    vector<ll> subsets(vector<int> v) {
        int n = v.size();
        vector<ll> res(1LL << n, 0);
        for(ll i = 0; i < (1LL << n); ++i) {
            for(ll j = 0, val = i; val; ++j, val >>= 1) {
                if(val & 1) res[i] += v[j];
            }
        }
        
        return res;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        
        vector<int> first(nums.begin(), nums.begin() + n / 2);
        vector<int> second(nums.begin() + n / 2, nums.end());
        
        vector<ll> sub1 = subsets(first), sub2 = subsets(second);
        sort(sub2.begin(), sub2.end());
        
        ll mn = INT_MAX;
        for(auto x: sub1) {
            int ind = lower_bound(sub2.begin(), sub2.end(), goal - x) - sub2.begin();
            if(ind < sub2.size()) mn = min(mn, abs(x + sub2[ind] - 1LL * goal));
            if(ind > 0) mn = min(mn, abs(x + sub2[ind - 1] - 1LL * goal));
        }
        
        return mn;
    }
};