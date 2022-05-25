//Link: https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [&](vector<int>& x, vector<int>& y) {
            return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1];
        });
        
        vector<int> lis;
        for(int i = 0; i < v.size(); ++i) {
            if(lis.empty() or v[i][1] > lis.back()) lis.push_back(v[i][1]);
            else {
                int ind = lower_bound(lis.begin(), lis.end(), v[i][1]) - lis.begin();
                lis[ind] = v[i][1];
            }
        }
        
        return lis.size();
    }
};