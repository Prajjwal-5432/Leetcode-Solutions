//Link: https://leetcode.com/problems/distinct-subsequences-ii/
//Refer: https://leetcode.com/problems/distinct-subsequences-ii/discuss/1501260/940.-White-Board-Intuition-%2B-Code-C%2B%2B-O(N)-Time-O(N)-Space

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<long long> dp(n + 1, 0), ind(26, -1);
        long long mod = 1e9 + 7;
        
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i] * 2;
            dp[i + 1] %= mod;
            if(ind[s[i] - 'a'] >= 0)
                dp[i + 1] -= dp[ind[s[i] - 'a']];
            if(dp[i + 1] < 0) dp[i + 1] += mod;
            ind[s[i] - 'a'] = i;
        }
        dp[n]--;
        return dp[n];
    }
};