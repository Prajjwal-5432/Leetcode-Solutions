//Link: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/

class Solution {
public:
    int util(vector<int> a, vector<int> b) {
        int res = 0;
        
        unordered_map<int, int> mp;
        for(auto x: b) mp[x]++;
        
        for(auto x: a) {
            long long target = 1LL * x * x;
            for(auto [val, cnt]: mp) {
                if(target % val != 0 or mp.count(target / val) == 0) continue;
                else if(target / val == val) res += cnt * (cnt - 1);
                else res += cnt * mp[target / val];
            }
        }
        return res / 2;
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        return util(nums1, nums2) + util(nums2, nums1);
    }
};