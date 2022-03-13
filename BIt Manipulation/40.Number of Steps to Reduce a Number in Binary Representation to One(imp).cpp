//Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

class Solution {
public:
    int numSteps(string s) {
        int ans = 0, carry = 0;
        
        for(int i = s.length() - 1; i > 0; --i) {
            if(s[i] - '0' + carry == 1) {
                ans += 2, carry = 1;
            } else {
                ans++;
            }
        }
        
        return ans + carry;
    }
};