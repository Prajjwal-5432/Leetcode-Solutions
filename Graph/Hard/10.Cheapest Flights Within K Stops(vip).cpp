//Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

#define ll long long
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<ll> dis(n, LONG_MAX);
        dis[src] = 0;
        
        for(int i = 0; i < k + 1; ++i) {
            vector<ll> disc = dis;
            for(auto x: flights) {
                int u = x[0], v = x[1], cost = x[2];
                if(dis[u] < LONG_MAX)
                    disc[v] = min(disc[v], dis[u] + cost);
            }
            dis.swap(disc);
        }
        
        return dis[dst] == LONG_MAX ? -1 : dis[dst];
    }
};