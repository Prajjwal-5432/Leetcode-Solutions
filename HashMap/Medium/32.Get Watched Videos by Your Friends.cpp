//Link: https://leetcode.com/problems/get-watched-videos-by-your-friends/

class Solution {
public:
    const static int nx = 110;
    vector<int> graf[nx];
    bool vis[nx];
    int dis[nx];
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        
        for(int i = 0; i < n; ++i) {
            dis[i] = n + 1;
            for(auto x: friends[i]) {
                graf[i].push_back(x);
                graf[x].push_back(i);
            }
        }
        
        queue<int> q;
        q.push(id);
        dis[id] = 0;
        vis[id] = 1;
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            
            for(auto u: graf[v]) {
                if(!vis[u] and dis[v] + 1 < dis[u]) {
                    vis[u] = 1;
                    dis[u] = dis[v] + 1;
                    q.push(u);
                }
            }
        }
        
        unordered_map<string, int> mp;
        
        for(int i = 0; i < n; ++i) {
            if(dis[i] == level) {
                for(auto x: watchedVideos[i]) mp[x]++;
            }
        }
        
        vector<pair<string, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [&](auto x, auto y) {
            return x.second != y.second ? x.second < y.second : x.first < y.first;
        });
        
        vector<string> ans;
        for(auto [x, y]: v) {
            ans.push_back(x);
        }
        
        return ans;
    }
};