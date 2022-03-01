//Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = nums.size();
        vector<int> lr(n, n), rl(n, -1);

        vector<int> v, s;
        for(int i = 0; i < n; ++i) {
            while(!v.empty() and nums[v.back()] > nums[i]) {
                lr[v.back()] = i;
                v.pop_back();
            }
            while(!s.empty() and nums[s.back()] > nums[n - i - 1]) {
                rl[s.back()] = n - i - 1;
                s.pop_back();
            }
            v.push_back(i);
            s.push_back(n - i - 1);
        }

        int rec = 0;
        for(int i = 0; i < n; ++i) {
            rec = max(rec, (lr[i] - rl[i] - 1) * nums[i]);
        }

        return rec;
    }
};