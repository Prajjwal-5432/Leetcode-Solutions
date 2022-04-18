//Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto x: nums) mp[x]++;
        
        int pairs = 0;
        for(auto [x, y]: mp) {
            if(2 * x == k) {
                pairs += (mp[x] / 2);
                mp[x] = 0;
            } else if(mp.count(k - x)) {
                int mn = min(y, mp[k - x]);
                pairs += mn;
                mp[x] -= mn, mp[k - x] -= mn;
            }
        }
        
        return pairs;
    }
};