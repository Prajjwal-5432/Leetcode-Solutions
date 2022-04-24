//Link: https://leetcode.com/problems/escape-a-large-maze/

class Solution {
public:
    unordered_set<string> pres;
    
    bool canGo(int r, int c, int tx, int ty) {
        queue<array<int, 2>> q;
        q.push({r, c});
        
        unordered_set<string> vis;
        vis.insert(to_string(r) + "." + to_string(c));
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        while(!q.empty()) {
            array<int, 2> v = q.front();
            q.pop();
            
            if(vis.size() > 20000) return 1;
            if(v[0] == tx and v[1] == ty) return 1;
            
            for(int t = 0; t < 4; ++t) {
                int x = v[0] + dx[t];
                int y = v[1] + dy[t];
                
                string key = to_string(x) + "." + to_string(y);
                
                if(min(x, y) >= 0 and max(x, y) < 1000000 and !vis.count(key) and !pres.count(key)) {
                    vis.insert(key);
                    q.push({x, y});
                }
            }
        }
        
        return 0;
    }
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto x: blocked) {
            pres.insert(to_string(x[0]) + "." + to_string(x[1]));
        }
        
        bool flag = canGo(source[0], source[1], target[0], target[1]);
        if(!flag) return 0;
        
        return canGo(target[0], target[1], source[0], source[1]);
    }
};