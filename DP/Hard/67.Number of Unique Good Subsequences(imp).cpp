//Link: https://leetcode.com/problems/number-of-unique-good-subsequences/

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        long long flag = 0, zero = 0, one = 0, mod = 1e9 + 7;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '1') 
                one = (one + zero + 1) % mod;
            else
                zero = (zero + one) % mod, flag = 1;
        }
        return (zero + one + flag) % mod;
    }
};