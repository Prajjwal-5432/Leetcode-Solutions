//Link: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size(), single = n / 3;
        
        vector<long long> min_vals(n), max_vals(n);
        priority_queue<int> mipq;
        
        long long sum = 0;
        for(int i = 0; i < 2 * single; ++i) {
            if(mipq.size() >= single) {
                if(nums[i] < mipq.top()) {
                    sum -= mipq.top();
                    mipq.pop();
                    mipq.push(nums[i]);
                    sum += nums[i];
                }
            } else {
                mipq.push(nums[i]);
                sum += nums[i];
            }
            min_vals[i] = sum;
        }
        
        priority_queue<int, vector<int>, greater<int>> mapq;
        sum = 0;
        for(int i = n - 1; i >= single; --i) {
            if(mapq.size() >= single) {
                if(nums[i] > mapq.top()) {
                    sum -= mapq.top();
                    mapq.pop();
                    sum += nums[i];
                    mapq.push(nums[i]);
                }
            } else {
                mapq.push(nums[i]);
                sum += nums[i];
            }
            max_vals[i] = sum;
        }
        
        long long best = 1e17;
        for(int i = single - 1; i < 2 * single; ++i) {
            long long val = min_vals[i] - max_vals[i + 1];
            best = min(best, val);
        }
        
        return best;
    }
};