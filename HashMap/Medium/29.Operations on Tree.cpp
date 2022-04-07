//Link: https://leetcode.com/problems/operations-on-tree/

class LockingTree {
public:
    vector<int> parent;
    vector<vector<int>> graf;
    unordered_map<int, int> mp;
    
    LockingTree(vector<int>& parent) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        
        this->parent = parent;
        int n = parent.size();
        
        graf.resize(n);
        
        for(int i = 1; i < n; ++i) {
            graf[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(!mp.count(num)) {
            mp[num] = user;
            return 1;
        }
        return 0;
    }
    
    bool unlock(int num, int user) {
        if(mp.count(num)) {
            if(mp[num] == user) {
                mp.erase(num);
                return 1;
            }
        }
        return 0;
    }
    
    bool ok;
    
    void dfs(int v) {
        if(mp.count(v)) {
            ok = 1;
            mp.erase(v);
        }   
        
        for(auto u: graf[v]) dfs(u);
    }
    
    bool upgrade(int num, int user) {
        bool flag = 0;
        for(int v = num; v != -1; v = parent[v]) {
            flag |= mp.count(v);
        }
        
        if(flag) return 0;
        
        ok = 0;
        dfs(num);
        if(!ok) return ok;
        
        mp[num] = user;
        
        return 1;
    }
};
