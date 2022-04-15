//Link: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
//Refer one loop solutions too

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> left(n);
        
        int best = INT_MAX, sum = 0;
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for(int i = 0; i < n; ++i) {
            sum += arr[i];
            
            if(mp.count(sum - target)) {
                best = min(best, i - mp[sum - target]);
            }
            
            left[i] = best;
            mp[sum] = i;
        }
        
        sum = 0;
        mp.clear();
        mp[0] = n;
        best = INT_MAX;
        
        vector<int> right(n);
        for(int i = n - 1; ~i; --i) {
            sum += arr[i];
            
            if(mp.count(sum - target)) {
                best = min(best, mp[sum - target] - i);
            }
            
            right[i] = best;
            mp[sum] = i;
        }
        
        best = INT_MAX;
        
        for(int i = 1; i < n; ++i) {
            if(max(left[i - 1], right[i]) != INT_MAX) {
                best = min(best, left[i - 1] + right[i]);
            }
        }
        
        return best == INT_MAX ? -1 : best;
    }
};