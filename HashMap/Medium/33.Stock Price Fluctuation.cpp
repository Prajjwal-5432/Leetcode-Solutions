//Link: https://leetcode.com/problems/stock-price-fluctuation/

class StockPrice {
public:
    unordered_map<int, int> stamp;
    map<int, int> mp;
    int latest;
    
    StockPrice() {
       ios_base::sync_with_stdio(false);
       cin.tie(NULL), cout.tie(NULL);
    }
    
    void update(int timestamp, int price) {
        if(stamp.count(timestamp)) {
            int cur = stamp[timestamp];
            stamp[timestamp] = price;
            
            mp[cur]--;
            mp[price]++;
            
            if(!mp[cur]) mp.erase(cur);
        } else {
            stamp[timestamp] = price;
            mp[price]++;
        }
        latest = max(latest, timestamp);
    }
    
    int current() {
        return stamp[latest];
    }
    
    int maximum() {
        return mp.rbegin()->first;
    }
    
    int minimum() {
        return mp.begin()->first;
    }
};