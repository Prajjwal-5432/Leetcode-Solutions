//Link: https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> avg;
    unordered_map<int, pair<string, int>> entry;
    
    UndergroundSystem() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    void checkIn(int id, string stationName, int t) {
        entry[id] = {stationName, t}; 
    }
    
    void checkOut(int id, string stationName, int t) {
        string station1 = entry[id].first;
        
        avg[station1 + "-" + stationName].first += t - entry[id].second;
        avg[station1 + "-" + stationName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string travel = startStation + "-" + endStation;
        
        double avgTime = avg[travel].first / (double)avg[travel].second;
        
        return avgTime;
    }
};