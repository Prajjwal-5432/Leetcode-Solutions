//Link: https://leetcode.com/problems/groups-of-strings/

class Solution {
public:
    vector<int> par, siz;
    int groups, largest;
    
    void uset(int u, int v) {
        u = fset(u);
        v = fset(v);
        
        if(u != v) {
            par[v] = u;
            siz[u] += siz[v];
            groups--;
            largest = max(largest, siz[u]);
        }
    }
    
    int fset(int v) {
        return v == par[v] ? v : par[v] = fset(par[v]);
    }
    
    vector<int> groupStrings(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n = words.size();
        groups = n, largest = 1;
        
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.resize(n, 1);
        
        unordered_map<int, int>mp;
        
        for(int i = 0; i < n; ++i) {
            int mask = 0;
            for(auto x: words[i]) mask |= (1 << (x - 'a'));
            
            for(int j = 0; j < 26; ++j) {
                int newMask = mask | (1 << j);
                
                if(mp.count(newMask)) 
                    uset(mp[newMask], i);
                
                mp[newMask] = i;
            }
        }    
        
        return {groups, largest};
    }
};