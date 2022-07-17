//Link: https://leetcode.com/problems/k-inverse-pairs-array/

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<long long> dp(k + 1, 0);
        long long mod = 1e9 + 7;
        
        for(int i = 1; i <= n; ++i) {
            vector<long long> ndp(k + 1, 0);
            for(int j = 0; j <= k; ++j) {
                if(j == 0) {
                    ndp[j] = 1;
                } else {
                    ndp[j] = (dp[j] - (j >= i ? dp[j - i] : 0) + mod) % mod;
                    ndp[j] = (ndp[j - 1] + ndp[j]) % mod;
                }
            }
            dp = ndp;
        }
        return (dp[k] - (k ? dp[k - 1] : 0) + mod) % mod;
    }
};