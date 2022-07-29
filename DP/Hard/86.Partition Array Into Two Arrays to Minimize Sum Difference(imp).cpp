//Link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
//Refer: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/discuss/1513298/C%2B%2B-Meet-In-Middle

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        long N = nums.size(), n = N / 2, tot = accumulate(nums.begin(), nums.end(), 0L);
        
        vector<vector<long>> lv(n + 1), rv(n + 1);
        
        for(int i = 0; i < (1 << n); ++i) {
            long s1 = 0, s2 = 0, bits = 0;
            for(int j = 0; j < n; ++j) {
                if(i >> j & 1) {
                    s1 += nums[j];
                    s2 += nums[n + j];
                    bits++;
                }
            }
            lv[bits].push_back(s1);
            rv[bits].push_back(s2);
        }
        
        for(int i = 0; i < n + 1; ++i)
            sort(rv[i].begin(), rv[i].end());
        
        long res = min(abs(tot - 2 * lv[n][0]), abs(tot - 2 * rv[n][0]));
        for(int i = 1; i < n; ++i) {
            for(auto &a: lv[i]) {
                long b = (tot - 2 * a) / 2, lef = n - i;
                auto it = lower_bound(rv[lef].begin(), rv[lef].end(), b);
                
                if(it != rv[lef].end())
                    res = min(res, abs(tot - 2 * (a + *it)));
                if(it != rv[lef].begin())
                    res = min(res, abs(tot - 2 * (a + *prev(it))));
            }
        }
        
        return res;
    }
};