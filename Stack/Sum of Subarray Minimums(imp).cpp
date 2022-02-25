//Link: https://leetcode.com/problems/sum-of-subarray-minimums/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> lr(n, n), rl(n, -1);
        
        vector<int> v;
        
        for(int i = 0; i < n; ++i) {
            //Take care in one of them use <= and in other don't
            while(!v.empty() and arr[i] <= arr[v.back()]) {
                lr[v.back()] = i;
                v.pop_back();
            }
            v.push_back(i);
        }
        
        v.clear();
        
        for(int i = n - 1; i >= 0; --i) {
            while(!v.empty() and arr[i] < arr[v.back()]) {
                rl[v.back()] = i;
                v.pop_back();
            }
            v.push_back(i);
        }
        
        long long res = 0, mod = 1e9 + 7;
        
        for(int i = 0; i < n; ++i) {
            int left = lr[i] - i, right = i - rl[i];
            int subs = left * right;
            res = (res % mod + (subs % mod * arr[i] % mod) % mod) % mod;
        }
        
        return res;
    }
};