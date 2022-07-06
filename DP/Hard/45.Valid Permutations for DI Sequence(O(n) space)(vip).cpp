//Link: https://leetcode.com/problems/valid-permutations-for-di-sequence/
//Refer: https://leetcode.com/problems/valid-permutations-for-di-sequence/discuss/168612/Top-down-with-Memo-greater-Bottom-up-DP-greater-N3-DP-greater-N2-DP-greater-O(N)-space
class Solution {
public:
    int numPermsDISequence(string s) {
        int n = s.size(), mod = 1e9 + 7;
        
        vector<long> dp1(n + 1, 1), dp2(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= i; ++j) {
                dp2[j] = j ? dp2[j - 1] : 0;
                if(s[i - 1] == 'D')
                    dp2[j] += dp1[i - 1] - (j ? dp1[j - 1] : 0);
                else
                    dp2[j] += j ? dp1[j - 1] : 0;
                
                dp2[j] = (dp2[j] + mod) % mod;
            }
            dp1 = dp2;
        }
        
        return dp1[n];
    }
};