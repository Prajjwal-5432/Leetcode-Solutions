//Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        
        for(int i = left; i < right + 1; ++i) {
            int bits = bitset<32> (i).count();
            cnt += primes.count(bits);
        }
        
        return cnt;
    }
};