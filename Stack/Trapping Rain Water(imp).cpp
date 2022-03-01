//Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n = height.size();
        vector<int> rmax(n);
        rmax[n - 1] = height[n - 1];
        
        for(int i = n - 2; ~i; --i) rmax[i] = max(rmax[i + 1], height[i]);
        
        int mx = 0, water = 0;
        for(int i = 0; i < n - 1; ++i) {
            mx = max(mx, height[i]);
            water += min(mx, rmax[i]) - height[i];
        }
        
        return water;
    }
};