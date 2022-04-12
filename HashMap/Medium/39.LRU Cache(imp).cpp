//Link: https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    int cap;
    unordered_map<int, int> mp;
    unordered_map<int, list<int>::iterator> pointer;
    list<int> lru;
    
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        if(mp.count(key) == 0) return -1;
        
        updateLRU(key);
        return mp[key];
    }
    
    void updateLRU(int key) {
        if(pointer.count(key)) 
            lru.erase(pointer[key]);
        
        lru.push_front(key);
        pointer[key] = lru.begin();
    }
    
    void removeKey() {
        mp.erase(lru.back());
        pointer.erase(lru.back());
        lru.pop_back();
    }
    
    void put(int key, int value) {
        if(mp.size() == cap and mp.count(key) == 0) 
            removeKey();
        
        updateLRU(key);
        mp[key] = value;
    }
};