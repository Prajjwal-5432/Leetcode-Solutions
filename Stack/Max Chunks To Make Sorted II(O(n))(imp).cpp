//Link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n = arr.size();
        vector<int> rmin(n);
        
        rmin[n - 1] = arr[n - 1];
        for(int i = n - 2; ~i; --i) rmin[i] = min(rmin[i + 1], arr[i]);
        
        int mx = -1, res = 1;
        for(int i = 0; i < n - 1; ++i) {
            mx = max(mx, arr[i]);
            res += mx <= rmin[i + 1];
        }
        
        return res;
    }
};