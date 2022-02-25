//Link: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if(is_sorted(arr.begin(), arr.end())) return 0;
        
        arr.insert(arr.begin(), INT_MIN);
        arr.push_back(INT_MAX);
        
        int n = arr.size();
        vector<int> pre(n, 0);
        
        for(int i = 1; i < n; ++i) {
            pre[i] += (arr[i] >= arr[i - 1] ? pre[i - 1] + 1 : 0);
        }
        
        int l = 1, best = n - 3;
        
        for(int i = 1; i < n - 1; ++i) {
            int left_check = pre[l - 1] - pre[0] + 1 == l;
            int right_check = pre.back() - pre[i + 1] + 1 == n - 1 - i;
            int sorted_check = arr[i + 1] >= arr[l - 1];
            
            while(l <= i and left_check and right_check and sorted_check) {
                best = min(best, i - l++ + 1);
                left_check = pre[l - 1] - pre[0] + 1 == l;
                right_check = pre.back() - pre[i + 1] + 1 == n - 1 - i;
                sorted_check = arr[i + 1] >= arr[l - 1];
            }
        }
        
        return best;
    }
};