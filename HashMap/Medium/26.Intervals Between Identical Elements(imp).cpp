//Link: https://leetcode.com/problems/intervals-between-identical-elements/

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        
        unordered_map<int, vector<int>> mp;
        
        int n = arr.size();
        for(int i = 0; i < n; ++i) {
            mp[arr[i]].push_back(i);
        }
        
        vector<long long> res(n, 0);
        
        for(auto [x, y]: mp) {
            long long len = y.size(), tot = accumulate(y.begin(), y.end(), 0LL), sum = 0;
            
            for(int i = 0; i < len; ++i) {
                tot -= y[i];
                res[y[i]] += 1LL * y[i] * i - sum;
                res[y[i]] += tot - 1LL * y[i] * (len - i - 1);
                sum += y[i];
            }
        }
        
        return res;
    }
};