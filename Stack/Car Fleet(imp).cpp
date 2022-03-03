//Link: https://leetcode.com/problems/car-fleet/

//First sort the cars by their positions
//Then check from right to left
//If a car has a greater speed than the car its right
//check if it can catch that car fleet
//If yes don't push it in the stack else do so

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = position.size();
        vector<array<int, 2>> cars(n);
        
        for(int i = 0; i < n; ++i) cars[i] = {position[i], speed[i]};
        
        sort(cars.begin(), cars.end());
        
        vector<array<int, 2>> st;
        
        for(int i = n - 1; i >= 0; --i) {
            if(st.empty() or cars[i][1] <= st.back()[1]) st.push_back(cars[i]);
            else {
                double time1 = (target - st.back()[0]) / (double) (st.back()[1]);
                double time2 = (st.back()[0] - cars[i][0]) / (double) (cars[i][1] - st.back()[1]);
                if(time2 > time1) {
                    st.push_back(cars[i]);
                } 
            }
        }
        
        return st.size();
    }
};