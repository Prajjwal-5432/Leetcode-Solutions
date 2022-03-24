//Link: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto x: nums) 
            for(auto y: nums)
                mp[x & y]++;
        
        int ans = 0;
        for(auto [x, y]: mp) 
            for(auto num: nums) 
                if((num & x) == 0) ans += y;
        
        return ans;
    }
};