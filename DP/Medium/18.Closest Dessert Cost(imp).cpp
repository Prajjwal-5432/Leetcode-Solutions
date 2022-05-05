//Link: https://leetcode.com/problems/closest-dessert-cost/

class Solution {
public:
    int res = 0;
    
    void buy(int cur, vector<int> &toppingCosts, int ind, int target) {
        if(abs(cur - target) < abs(target - res) or (abs(cur - target) == abs(target - res) and cur < res)) {
            res = cur;
        }
        
        if(ind == toppingCosts.size() or cur >= target) return;
        
        buy(cur, toppingCosts, ind + 1, target);
        buy(cur + toppingCosts[ind], toppingCosts, ind + 1, target);
        buy(cur + 2 * toppingCosts[ind], toppingCosts, ind + 1, target);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        res = baseCosts[0];
        
        for(auto x: baseCosts) {
            buy(x, toppingCosts, 0, target);
        }
        
        return res;
    }
};