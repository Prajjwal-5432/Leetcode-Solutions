//Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        
        int cnt = 1;
        for(auto x: arr) {
            mp[x] = max(mp[x - difference] + 1, 1);
            cnt = max(cnt, mp[x]);
        }
        
        return cnt;
    }
};