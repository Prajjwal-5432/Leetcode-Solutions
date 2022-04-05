//Link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution {
public:
    const static int nx = 1e5 + 100;
    vector<int> graf[nx];
    vector<bool> hasApple;
    bool vis[nx];
    
    pair<int, bool> dfs(int v) {
        if(vis[v]) return {1, 0};
        
        vis[v] = 1;
        bool foundApple = hasApple[v];
        int totalTime = 0;
        
        for(auto u: graf[v]) {
            pair<int, bool> ans = dfs(u);
            
            if(ans.second) {
                foundApple = 1;
                totalTime += ans.first + 1;
            }    
        }
        
        return {totalTime + 1, foundApple};
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        
        this->hasApple = hasApple;
        
        for(auto x: edges) {
            graf[x[0]].push_back(x[1]);
            graf[x[1]].push_back(x[0]);
        }
        
        pair<int, bool> ans = dfs(0);
        
        return ans.second ? ans.first - 1 : 0;
    }
};