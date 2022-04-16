//Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
//Refer: Leetcode's solution

class Solution {
public:
    struct comp {
        bool operator()(array<int, 2> a, array<int, 2> b) {
            return a[1] == b[1] ? (a[1] - a[0]) > (b[1] - b[0]) : a[1] > b[1];
        }
    };
    
    bool isPossible(vector<int>& nums) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, comp> pq;
        
        for(auto num: nums) {
            while(!pq.empty() and pq.top()[1] + 1 < num) {
                array<int, 2> cur = pq.top();
                pq.pop();
                
                if(cur[1] - cur[0] + 1 < 3) return false;
            }
            
            if(pq.empty() or pq.top()[1] == num) {
                pq.push({num, num});
            } else {
                array<int, 2> cur = pq.top();
                pq.pop();
                
                cur[1] = num;
                pq.push(cur);
            }
        }
        
        while(!pq.empty()) {
            array<int, 2> v = pq.top();
            pq.pop();
            
            if(v[1] - v[0] + 1 < 3) return false;
        }
        
        return true;
    }
};