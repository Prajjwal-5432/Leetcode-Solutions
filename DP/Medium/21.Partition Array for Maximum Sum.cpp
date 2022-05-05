//Link: https://leetcode.com/problems/partition-array-for-maximum-sum/

const int nx = 550;
long dp[nx];

class Solution {
public:
    int k, n;
    vector<int> arr;
    
    long func(int ind) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        long ans = 0, mx = 0;
        for(int i = ind; i < min(n, ind + k); ++i) {
            mx = max(mx, 1L * arr[i]);
            ans = max(ans, (i - ind + 1) * mx + func(i + 1));
        }
        
        return dp[ind] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k = k;    
        this->arr = arr;
        n = arr.size();
        
        memset(dp, -1, sizeof dp);
        
        return func(0);
    }
};