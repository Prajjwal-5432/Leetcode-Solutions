//Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/
//Look at leetcode hints

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = heights.size();
        vector<int> st, ans(n);
        
        for(int i = n - 1; ~i; --i) {
            if(st.empty() or st.front() <= heights[i]) ans[i] = st.size();
            else if(heights[i] < st.back()) ans[i] = 1;
            else {
                int lo = 0, hi = st.size() - 1, ind;
                while(lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if(st[mid] <= heights[i]) {
                        ind = mid;
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                ans[i] = st.size() - ind + 1;
            }
            while(!st.empty() and st.back() <= heights[i]) st.pop_back();
            st.push_back(heights[i]);
        }
        
        return ans;
    }
};