//Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
//Refer: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/discuss/961350/C%2B%2B-O(N)-time-iterative

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0, mod = 1e9 + 7;
        int len = 0;
        for(int i = 1; i < n + 1; ++i) {
            if((i & (i - 1)) == 0) len++;
            ans = ((ans << len) % mod + i) % mod;
        }
        
        return ans;
    }
};