//Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
//Refer: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/574923/JavaC%2B%2BPython-DP-O(1)-Space

class Solution {
public:
    int numOfWays(int n) {
        long a121 = 6, a123 = 6, mod = 1e9 + 7;
        
        for(int i = 2; i <= n; ++i) {
            long b121 = a121 * 3 + a123 * 2;
            long b123 = a121 * 2 + a123 * 2;
            a121 = b121 % mod;
            a123 = b123 % mod;
        }
        
        return (int)(a123 + a121) % mod;
    }
};