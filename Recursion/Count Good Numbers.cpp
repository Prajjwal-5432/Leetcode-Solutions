//Link: https://leetcode.com/problems/count-good-numbers/
class Solution {
public:
    long long pow(long long a, long long n) {
        long long ret = 1;
        long long mod = 1e9 + 7;
        while (n > 0) {
            if (n & 1) ret = ret * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return ret % mod;
    }
    int countGoodNumbers(long long n) {
        if(n & 1) {
            return (pow(5, n / 2 + 1) * pow(4, n / 2)) % mod;
        } else {
            return (pow(5, n / 2) * pow(4, n / 2)) % mod;
        }
    }
};