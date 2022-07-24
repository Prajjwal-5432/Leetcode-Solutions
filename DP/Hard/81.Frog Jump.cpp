//Link: https://leetcode.com/problems/frog-jump/

int dp[2222][5555];
class Solution {
public:
    unordered_map<long long, int> index;
    bool dfs(int ind, int k, vector<int> &stones) {
        if(ind == stones.size() - 1) return 1;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        bool ans = 0;
        if(index.count(stones[ind] + k - 1) and k > 1)
            ans |= dfs(index[stones[ind] + k - 1], k - 1, stones);
        if(index.count(stones[ind] + k)) 
            ans |= dfs(index[stones[ind] + k], k, stones);
        if(index.count(stones[ind] + k + 1))
            ans |= dfs(index[stones[ind] + k + 1], k + 1, stones);
        
        return dp[ind][k] = ans;
    }
    bool canCross(vector<int>& stones) {
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < stones.size(); ++i) {
            index[stones[i]] = i;
        }
        
        if(!index.count(1)) return 0;
        return dfs(index[1], 1, stones);
    }
};