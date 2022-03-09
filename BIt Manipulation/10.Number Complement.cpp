//Link: https://leetcode.com/problems/number-complement/

class Solution {
public:
    string s;
    
    void dec2bin(int n) {
        if(n / 2 != 0) dec2bin(n / 2);
        s += (n % 2) == 0 ? '1' : '0';
    }
    int findComplement(int num) {
        dec2bin(num);
        return stoll(s, 0, 2);
    }
};