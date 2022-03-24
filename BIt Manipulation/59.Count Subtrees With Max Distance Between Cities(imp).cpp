//Link: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<long>> d(n, vector<long> (n, INT_MAX));
        
        for(auto x: edges) d[x[0] - 1][x[1] - 1] = 1, d[x[1] - 1][x[0] - 1] = 1;
        for(int i = 0; i < n; ++i) d[i][i] = 0;
        
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
        
        vector<int> ans(n, 0);
        for(int i = 0; i < (1 << n); ++i) {
            vector<int> v;
            for(int j = 0, num = i; num; ++j, num >>= 1) {
                if(num & 1) v.push_back(j);
            }
            
            long mx = 0, edge = 0;
            for(int j = 0; j < v.size(); ++j) {
                for(int k = j + 1; k < v.size(); ++k) {
                    edge += d[v[j]][v[k]] == 1;
                    mx = max(mx, d[v[j]][v[k]]);
                }
            }
            if(edge == v.size() - 1) ans[mx]++;
        }
        
        return vector<int> (ans.begin() + 1, ans.end());
    }
};