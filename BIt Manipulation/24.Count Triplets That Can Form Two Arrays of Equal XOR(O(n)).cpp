//Link: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        
        unordered_map<int, int> count = {{0, 1}}, sum;
        
        for(int i = 0, val = 0; i < arr.size(); ++i) {
            val ^= arr[i];
            cnt += count[val] * i - sum[val];
            count[val]++;
            sum[val] += i + 1;
        }
        
        return cnt;
    }
};