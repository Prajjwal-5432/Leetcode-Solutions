//Link: https://leetcode.com/problems/two-best-non-overlapping-events/

#define max(a, b) a > b ? a : b

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int n = events.size();
        vector<int> mx(n);
        mx.back() = events.back()[2];
        
        
        for(int i = n - 2; ~i; --i) {
            mx[i] = max(mx[i + 1], events[i][2]);
        }
        
        long long best = 0;
        for(int i = 0; i < n; ++i) {
            best = max(best, events[i][2]);
            int l = i + 1, r = n - 1, ind = -1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(events[mid][0] > events[i][1]) {
                    ind = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if(ind != -1) {
                best = max(best, events[i][2] + mx[ind]);
            }
        }
        
        return best;
    }
};