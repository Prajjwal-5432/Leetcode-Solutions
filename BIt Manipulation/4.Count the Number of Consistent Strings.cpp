//Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        long msk = 0;
        for(auto x: allowed) msk |= (1 << (x - 'a'));
        
        int cnt = 0;
        for(auto x: words) {
            long wmsk = 0;
            for(auto y: x) wmsk |= (1 << (y - 'a'));
            
            cnt += ((msk & wmsk) == wmsk);
        }
        
        return cnt;
    }
};