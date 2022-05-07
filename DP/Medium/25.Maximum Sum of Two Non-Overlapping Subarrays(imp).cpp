//Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<long> pre(n + 1, 0);
        
        partial_sum(nums.begin(), nums.end(), pre.begin() + 1);
        
        long best = 0;
        for(int t = 0; t < 2; ++t, swap(firstLen, secondLen)) {
            long mx = 0;
            for(int i = 0; i < n - firstLen + 1; ++i) {
                int sum = pre[i + firstLen] - pre[i];
                best = max(best, sum + mx);
                
                if(i + 1 >= secondLen) {
                    mx = max(mx, pre[i + 1] - pre[i - secondLen + 1]);
                }
            }
        }
        
        return best;
    }
};