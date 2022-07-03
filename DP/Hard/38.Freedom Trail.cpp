//Link: https://leetcode.com/problems/freedom-trail/

class Solution {
public:
    int dp[111][111];
    string ring, key;
    
    int dfs(int i, int j) {
        if(j == key.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 123412;
        for(int nxt = 0; nxt < ring.size(); ++nxt) {
            if(ring[nxt] == key[j]) {
                ans = min(ans, abs(i - nxt) + 1 + dfs(nxt, j + 1));
                ans = min(ans, int(ring.size()) - abs(i - nxt) + 1 + dfs(nxt, j + 1));
            }
        }
        
        return dp[i][j] = ans;
    }    
    int findRotateSteps(string ring, string key) {
        memset(dp, -1, sizeof dp);      
        this->ring = ring;
        this->key = key;
        
        return dfs(0, 0);
    }
};