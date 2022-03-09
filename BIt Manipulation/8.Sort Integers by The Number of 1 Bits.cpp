//Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int x, int y) {
            int a = __builtin_popcount(x), b = __builtin_popcount(y);
            return a == b ? x < y : a < b;
        });
        
        return arr;
    }
};