//Link: https://leetcode.com/problems/numbers-with-repeated-digits/

class Solution {
public:
    long fib(long n) {
        return n ? fib(n - 1) * n : 1;
    }
    long npr(long n, long r) {
        return fib(n) / fib(n - r);
    }
    int numDupDigitsAtMostN(int n) {
        vector<int> nums;
        for(int i = n + 1; i > 0; i /= 10) {
            nums.push_back(i % 10);
        }
        reverse(nums.begin(), nums.end());
        
        long res = 0, len = nums.size();
        for(int i = 1; i < len; ++i) {
            res += 9 * npr(9, i - 1);
        }
        
        unordered_set<int> seen;
        for(int i = 0; i < len; ++i) {
            for(int j = i ? 0 : 1; j < nums[i]; ++j) {
                if(!seen.count(j)) {
                    res += npr(9 - i, len - i - 1);
                }
            }
            if(seen.count(nums[i])) break;
            seen.insert(nums[i]);
        }
        
        return n - res;
    }
};