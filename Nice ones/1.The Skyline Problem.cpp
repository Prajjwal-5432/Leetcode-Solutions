//Link: https://leetcode.com/problems/the-skyline-problem/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> walls;
        vector<vector<int>> res;
        for(auto x: buildings) {
            walls.push_back({x[0], -x[2]});
            walls.push_back({x[1], x[2]});
        }
        
        sort(walls.begin(), walls.end());
        
        int mx = 0;
        multiset<int> ms = {0};
        for(auto [x, y]: walls) {
            if(y < 0) 
                ms.insert(-y);
            else
                ms.erase(ms.find(y));
            
            if(*ms.rbegin() != mx)
                res.push_back({x, *ms.rbegin()}), mx = *ms.rbegin();
        }
        return res;
    }
};