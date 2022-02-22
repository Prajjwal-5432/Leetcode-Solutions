//Link: https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> v, ans(n, 0);
        
        for(int i = 0; i < n; ++i) {
            while(!v.empty() and temperatures[i] > temperatures[v.back()]) {
                ans[v.back()] = i - v.back();
                v.pop_back();
            }
            v.push_back(i);
        }
        
        return ans;
    }
};