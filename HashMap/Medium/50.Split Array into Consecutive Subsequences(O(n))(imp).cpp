//Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
//Refer Lee's solution

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, end;
        
        for(auto x: nums)
            left[x]++;
        
        for(auto x: nums) {
            if(left[x] == 0) continue;
            
            if(end[x - 1] > 0) {
                end[x - 1]--;
                end[x]++;
            } else if(left[x + 1] > 0 and left[x + 2] > 0) {
                left[x + 1]--, left[x + 2]--;
                end[x + 2]++;
            } else {
                return false;
            }
            left[x]--;
        }
        
        return true;
    }
};