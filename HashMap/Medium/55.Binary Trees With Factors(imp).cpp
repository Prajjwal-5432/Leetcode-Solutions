//Link: https://leetcode.com/problems/binary-trees-with-factors/

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long mod = 1e9 + 7;
        
        int n = arr.size();
        vector<long> dp(n, 1);
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) 
            mp[arr[i]] = i;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(arr[i] % arr[j] == 0) {
                    if(mp.count(arr[i] / arr[j])) 
                        dp[i] = (dp[i] + dp[j] * dp[mp[arr[i] / arr[j]]]) % mod;
                }
            }    
        }
        
        long tot = 0;
        for(auto x: dp) tot = (tot + x) % mod;
        
        return tot;
    }
};