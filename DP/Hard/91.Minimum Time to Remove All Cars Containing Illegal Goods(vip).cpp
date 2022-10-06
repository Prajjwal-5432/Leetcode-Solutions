//Link: https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/

class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        vector<int> lef(n, 0), rig(n, 0);
        lef[0] = (s[0] == '1');
        rig[n - 1] = (s[n - 1] == '1');
        
        for(int i = 1; i < n; ++i)
            lef[i] = s[i] == '1' ? min(lef[i - 1] + 2, i + 1) : lef[i - 1];
        
        for(int i = n - 2; ~i; --i)
            rig[i] = s[i] == '1' ? min(rig[i + 1] + 2, n - i) : rig[i + 1];
        
        int res = min(lef[n - 1], rig[0]);
        for(int i = 0; i < n - 1; ++i) 
            res = min(res, lef[i] + rig[i + 1]);
        
        return res;
    }
};