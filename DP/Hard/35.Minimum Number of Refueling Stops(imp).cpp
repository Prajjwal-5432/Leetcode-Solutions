//Link: https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) { 
        priority_queue<long> pq;
        int ans = 0;
        for(int i = 0; startFuel < target; ans++) {
            while(i < s.size() and startFuel >= s[i][0]) {
                pq.push(s[i++][1]);
            }
            if(pq.empty()) return -1;
            startFuel += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};