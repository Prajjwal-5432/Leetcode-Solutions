//Link: https://leetcode.com/problems/sum-of-total-strength-of-wizards/\

#define ll long long
class Solution {
public:
    int totalStrength(vector<int>& v) {
        ll n = v.size(), mod = 1e9 + 7;
        vector<ll> pre(n + 1, 0), presum(n + 2, 0);
        
        for(int i = 0; i < n; ++i) pre[i + 1] = (pre[i] + v[i]) % mod;
        for(int i = 0; i < n + 1; ++i) presum[i + 1] = (presum[i] + pre[i]) % mod;
        
        vector<int> st;
        vector<int> left(n, -1), right(n, n);
        
        for(int i = n - 1; ~i; --i) {
            while(!st.empty() and v[i] < v[st.back()]) {
                left[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        for(int i = 0; i < n; ++i) {
            while(!st.empty() and v[i] <= v[st.back()]) {
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        
        ll res = 0;
        
        for(int i = 0; i < n; ++i) {
            res += ((presum[right[i] + 1] - presum[i + 1]) * (i - left[i]) % mod + mod * 2 - 
                   (presum[i + 1] - presum[left[i] + 1]) * (right[i] - i) % mod) % mod * v[i] % mod;
            res %= mod;
        }
        
        return res;
    }
};