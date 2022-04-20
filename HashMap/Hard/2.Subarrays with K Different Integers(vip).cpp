//Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
//Refer votrubac's solution too

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
    int atMost(vector<int> v, int k) {
        unordered_map<int, int> mp;
        
        int res = 0, l = 0;
        for(int r = 0; r < v.size(); ++r) {
            if(mp[v[r]]++ == 0) k--;
            
            while(k < 0) {
                if(--mp[v[l]] == 0) k++;
                l++;
            }
            res += r - l + 1;
        }
        
        return res;
    }
};