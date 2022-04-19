//Link: https://leetcode.com/problems/minimum-area-rectangle/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        
        for(auto x: points) {
            mp[x[0]].insert(x[1]);
        }
        
        int area = INT_MAX, n = points.size();
        
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2 or y1 == y2) continue;
                
                if(mp.count(x1) and mp[x1].count(y2) and mp.count(x2) and mp[x2].count(y1)) {
                    area = min(area, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }
        
        return area == INT_MAX ? 0 : area;
    }
};