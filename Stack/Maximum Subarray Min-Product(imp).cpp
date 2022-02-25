//Link: https://leetcode.com/problems/maximum-subarray-min-product/submissions/
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> lr(n, n), rl(n, -1), pre(n + 1, 0);
        
        vector<int> v;
        for(int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
            while(!v.empty() and nums[i] < nums[v.back()]) {
                lr[v.back()] = i;
                v.pop_back();
            }
            v.push_back(i);
        }
        
        v.clear();
        
        for(int i = n - 1; i >= 0; --i) {
            while(!v.empty() and nums[i] < nums[v.back()]) {
                rl[v.back()] = i;
                v.pop_back();
            }
            v.push_back(i);
        }
        
        long long mx = 0, mod = 1e9 + 7;
        
        for(int i = 0; i < n; ++i) {
            long long sum = pre[lr[i]] - pre[rl[i] + 1];
            mx = max(mx, 1LL * nums[i] * sum);
        }
        
        return mx % mod;
    }
};