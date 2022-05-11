//Link: https://leetcode.com/problems/count-sorted-vowel-strings/

const int nx = 55;
long dp[nx][6];

class Solution {
public:
    int n;
    long func(int ind, int prev) {
        if(ind >= n) return 1;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        long ans = 0;
        for(int i = prev; i < 5; ++i) {
            ans += func(ind + 1, i);
        }
        
        return dp[ind][prev] = ans;
    }
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof dp);
        this->n = n;
        
        return func(0, 0);
    }
};