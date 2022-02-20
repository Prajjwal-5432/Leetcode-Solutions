//Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        
        int64_t len = (1 << n) - 1;
        int64_t mid = len - len / 2;
        
        if(k == mid) return '1';
        if(k < mid) return findKthBit(n - 1, k);
        
        int64_t prev = (1 << (n - 1)) - 1;
        return findKthBit(n - 1, prev - (k - mid) + 1) == '1' ? '0' : '1';
    }
};