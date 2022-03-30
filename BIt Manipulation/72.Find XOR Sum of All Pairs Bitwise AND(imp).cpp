//Link: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/

// a ^ b = a` . b + a . b`
//(a & b) ^ (a & c) = (a & b)` . (a & c) + (a & b) . (a & c)`
// applying demorgans law
// = (a` + b`) . (a & c) + (a & b) . (a` + c`)
// = a . b` .c + a . b. c`
// = a . (b` c + b c`)
// = a . (b ^ c)

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x = 0, y = 0;
        
        for(auto i: arr1) x ^= i;
        for(auto i: arr2) y ^= i;
        
        return x & y;
    }
};