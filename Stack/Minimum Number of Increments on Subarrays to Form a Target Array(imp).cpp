//Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
//Refer: https://www.youtube.com/watch?v=W5q_VfVfvjQ

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int op = 0;
        for(int i = 0; i < target.size(); ++i) {
            if(i == 0) op += target[i];
            else op += (target[i] <= target[i - 1] ? 0 : target[i] - target[i - 1]);
        }
        
        return op;
    }
};