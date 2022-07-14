//Link: https://leetcode.com/problems/minimum-cost-to-merge-stones/

long dp[33][33][33];

class Solution {
public:
    vector<int> pre;
    int k;
    
    long dfs(int i, int j, int piles, vector<int> &stones) {
        if(i == j) return (piles == 1) ? 0 : INT_MAX;
        if(dp[i][j][piles] != -1) return dp[i][j][piles];
        
        long res = INT_MAX;
        if(piles == 1) res = dfs(i, j, k, stones) + pre[j + 1] - pre[i];
        else {
            for(int split = i; split < j; ++split) {
                res = min(res, dfs(i, split, 1, stones) + dfs(split + 1, j, piles - 1, stones));
            }
        }
        
        return dp[i][j][piles] = res;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        
        if((n - 1) % (k - 1) != 0) return -1;
        
        memset(dp, -1, sizeof dp);
        this->k = k;
        pre.resize(stones.size() + 1, 0);
        partial_sum(stones.begin(), stones.end(), pre.begin() + 1);
        
        return dfs(0, n - 1, 1, stones);
    }
};