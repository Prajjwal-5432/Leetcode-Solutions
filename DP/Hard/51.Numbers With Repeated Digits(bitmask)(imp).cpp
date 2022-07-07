//Link: https://leetcode.com/problems/numbers-with-repeated-digits/

int dp[11][2][2][1 << 11];
//[len][flag][repeated][mask]

class Solution {
public:
    int dfs(int ind, int flag, int repeat, int mask, string& s) {
        if(ind == s.length()) return repeat;
        if(dp[ind][flag][repeat][mask] != -1) return dp[ind][flag][repeat][mask];
        
        int limit = flag ? 9 : s[ind] - '0';
        int ans = 0;
        for(int i = 0; i <= limit; ++i) {
            if(i < s[ind] - '0') {
                if(i == 0 and mask == 0)
                    ans += dfs(ind + 1, 1, 0, mask, s);
                else if(mask >> i & 1)
                    ans += dfs(ind + 1, 1, 1, mask, s);
                else
                    ans += dfs(ind + 1, 1, repeat, mask | (1 << i), s);
            } else {
                if(i == 0 and mask == 0)
                    ans += dfs(ind + 1, flag, 0, mask, s);
                else if(mask >> i & 1)
                    ans += dfs(ind + 1, flag, 1, mask, s);
                else
                    ans += dfs(ind + 1, flag, repeat, mask | (1 << i), s);
            }
        }
        
        return dp[ind][flag][repeat][mask] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof dp);
        string s = to_string(n);
        
        return dfs(0, 0, 0, 0, s);
    }
};