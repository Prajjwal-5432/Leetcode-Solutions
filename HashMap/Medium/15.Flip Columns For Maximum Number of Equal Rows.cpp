//Link: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> flips;
        
        for(auto x: matrix) {
            string a, b;
            for(auto y: x) {
                a += char(y + '0');
                b += (y ? '0' : '1');
            }
            
            if(flips.count(b)) flips[b]++;
            else flips[a]++;
        }
        
        int mx = 0;
        for(auto [x, y]: flips) 
            mx = max(mx, y);
        
        return mx;
    }
};