//Link: https://leetcode.com/problems/lfu-cache/

class LFUCache {
public:
    map<int, list<int>> cache;
    unordered_map<int, list<int>::iterator> pos;
    unordered_map<int, int> val, cnt;
    int cap;
    
    LFUCache(int capacity): cap(capacity) {
        
    }
    
    int get(int key) {
        if(!val.count(key)) return -1;
        
        int c = cnt[key];
        cache[c].erase(pos[key]);
        pos.erase(key);
        if(cache[c].empty()) cache.erase(c);
        
        update(key, val[key]);
        
        return val[key];
    }
    
    void deleteKey() {
        int small = cache.begin()->first;
            
        int last = cache[small].back();
        cache[small].pop_back();
        pos.erase(last);
        cnt.erase(last);
        val.erase(last);
        
        if(cache[small].empty()) cache.erase(small);
    }
    
    void update(int key, int value) {
        val[key] = value;
        cnt[key] += 1;
        cache[cnt[key]].push_front(key);
        pos[key] = cache[cnt[key]].begin();
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(val.count(key)) {
            int c = cnt[key];
            
            cache[c].erase(pos[key]);
            pos.erase(key);
            if(cache[c].empty()) cache.erase(c);
            
            update(key, value);
        } else if(val.size() == cap) {
            deleteKey();
            update(key, value);
        } else {
            update(key, value);
        }
    }
};