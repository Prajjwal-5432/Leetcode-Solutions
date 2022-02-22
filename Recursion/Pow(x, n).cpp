//Link: https://leetcode.com/problems/powx-n/
class Solution {
public:
    double power(long double a, int n) {
        long double ret = 1;
        while (n > 0) {
            if (n & 1) ret = ret * a;
            a = a * a;
            n >>= 1;
        }
        return ret;
    }
    double myPow(double x, int n) {
        return (n < 0 ? 1 / (double) power(x, abs(n)) : power(x, n));
    }
};