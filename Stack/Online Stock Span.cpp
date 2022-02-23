//Link: https://leetcode.com/problems/online-stock-span/
class StockSpanner {
public:
    vector<pair<int, int>> v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while(!v.empty() and price >= v.back().first) {
            cnt += v.back().second;
            v.pop_back();
        }
        v.push_back({price, cnt});
        
        return cnt;
    }
};
