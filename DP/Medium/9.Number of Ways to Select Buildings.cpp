//Link: https://leetcode.com/problems/number-of-ways-to-select-buildings/

class Solution {
public:
    long long left[2], right[2];
    long long numberOfWays(string s) {
        for(auto x: s) right[x - '0']++;
        
        long long cnt = 0;
        for(auto x: s) {
            left[x - '0']++;
            right[x - '0']--;
            
            if(x == '1') {
                cnt += left[0] * right[0];
            } else {
                cnt += left[1] * right[1];
            }
        }
        
        return cnt;
    }
};