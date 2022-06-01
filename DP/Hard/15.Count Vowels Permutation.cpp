//Link: https://leetcode.com/problems/count-vowels-permutation/

#define ll long long
const int nx = 2e4 + 100;
ll dp[nx][6];
ll mod;
string can[] = {"01000", "10100", "11011", "00101", "10000"};

class Solution {
public:
    int n;
    ll func(int ind, int prev) {
        if(ind == n) return 1;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        ll ans = 0;
        for(int i = 0; i < 5; ++i) {
            if(can[prev][i] == '1') (ans += func(ind + 1, i)) %= mod;
        }
        
        return dp[ind][prev] = ans;
    }
    
    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
        this->n = n;
        ll ans = 0;
        for(int i = 0; i < 5; ++i) (ans += func(1, i)) %= mod;
        
        return ans;
    }
};