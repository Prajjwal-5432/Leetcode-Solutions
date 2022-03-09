//Link: https://leetcode.com/problems/xor-operation-in-an-array/
class Solution {
public:
    int xorOperation(int n, int start) {
        int val = 0, num = start;
        for(int i = 0; i < n; ++i) {
            num = start + 2 * i;
            val ^= num;
        }
        return val;
    }
};