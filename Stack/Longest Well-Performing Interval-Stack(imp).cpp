https://leetcode.com/problems/longest-well-performing-interval/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        
        vector<int> pre(n + 1, 0);
        
        for(int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (hours[i] > 8 ? 1 : -1);
        }
        
        vector<int> st;
        for(int i = 0; i < n + 1; ++i) {
            if(st.empty() or pre[st.back()] > pre[i]) st.push_back(i);
        }
        
        int ans = 0;
        for(int i = n; i >= 0; --i) {
            while(!st.empty() and pre[st.back()] < pre[i]) {
                ans = max(ans, i - st.back());
                st.pop_back();
            }
            if(!st.empty() and st.back() == i) st.pop_back();
        }
        
        return ans;
    }
};