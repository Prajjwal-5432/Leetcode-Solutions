//Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/
//Refer: https://leetcode.com/problems/number-of-visible-people-in-a-queue/discuss/1363940/C%2B%2BJavaPython-Monotonic-stack-Visualize-picture-Clean-and-Concise

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = heights.size();
        vector<int> st, ans(n, 0);
        
        for(int i = n - 1; ~i; --i) {
            while(!st.empty() and heights[i] > st.back()) st.pop_back(), ans[i]++;
            if(!st.empty()) ans[i]++;
            
            st.push_back(heights[i]);
        }
        
        return ans;
    }
};