//Link: https://leetcode.com/problems/jump-game-v/
const int nx = 1e3 + 100;
int dp[nx];

class Solution {
public:
    int d;
    vector<int> arr;

    int func(int ind) {
        if(dp[ind] != -1) return dp[ind];
        
        int ans = 1;
        for(int i = ind + 1; i <= min(ind + d, int(arr.size()) - 1) and arr[i] < arr[ind]; ++i) {
            ans = max(ans, 1 + func(i));
        }
        for(int i = ind - 1; i >= max(0, ind - d) and arr[i] < arr[ind]; --i) {
            ans = max(ans, 1 + func(i));
        }
        
        return dp[ind] = ans;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        memset(dp, -1, sizeof dp);
        this->d = d;
        this->arr = arr;
        
        int ans = 1;
        for(int i = 0; i < arr.size(); ++i) {
            ans = max(ans, func(i));
        }
        
        return ans;
    }
};