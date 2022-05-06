//Link: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    
    int func(int eggs, int floor) {
        if(eggs == 1) return floor;
        if(floor <= 1) return floor;
        
        if(dp[eggs][floor] != -1) return dp[eggs][floor];
        
        int ans = n * 100;
        for(int i = 1; i <= floor; ++i) {
            int temp = 1 + max(func(eggs - 1, i - 1), func(eggs, floor - i));
            ans = min(ans, temp);
        }
        
        return dp[eggs][floor] = ans;
    }
    
    int twoEggDrop(int n) {
        int eggs = 2;
        this->n = n;
        
        dp.resize(eggs + 2, vector<int> (n + 2, -1));
        
        return func(eggs, n);
    }
};