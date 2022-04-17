//Link: https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        
        vector<int> v(n);
        v[0] = 1;
        
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; ++i) {
            int mn = min({v[p2] * 2, v[p3] * 3, v[p5] * 5});
            
            v[i] = mn;
            
            p2 += v[i] == v[p2] * 2;
            p3 += v[i] == v[p3] * 3;
            p5 += v[i] == v[p5] * 5;
        }
        
        return v[n - 1];
    }
};