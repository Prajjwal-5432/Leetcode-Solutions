//Link: https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n = height.size();
        
        int mxl = height[0], mxr = height[n - 1];
        int l = 1, r = n - 2, water = 0;
        
        while(l <= r) {
            if(mxl < mxr) {
                mxl = max(mxl, height[l]);
                water += mxl - height[l++];
            } else {
                mxr = max(mxr, height[r]);
                water += mxr - height[r--];
            }
        }
        
        return water;
    }
};