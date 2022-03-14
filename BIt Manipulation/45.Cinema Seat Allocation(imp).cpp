//Link: https://leetcode.com/problems/cinema-seat-allocation/
//suprisingly unordered map also works
    
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        unordered_map<int, int> mp;
        
        for(auto x: reservedSeats) mp[x[0]] |= (1 << x[1]);
        
        int tot = 0, prev = 0;
        
        for(auto [x, y]: mp) {
            int left = 0, mid = 0, right = 0;
            for(int i = 2; i <= 5; ++i) left |= ((y >> i) & 1);
            for(int i = 4; i <= 7; ++i) mid |= ((y >> i) & 1);
            for(int i = 6; i <= 9; ++i) right |= ((y >> i) & 1);
            
            if(left == 0 and right == 0) tot += 2;
            else if(left == 0 or right == 0 or mid == 0) tot += 1;
            
            tot += (x - prev - 1) * 2;
            prev = x;
        }
        
        if(prev != n) tot += (n - prev) * 2;
        
        return tot;
    }
};