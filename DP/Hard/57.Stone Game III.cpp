//Link: https://leetcode.com/problems/stone-game-iii/

int dp[50010][2];
class Solution {
public:
    int dfs(int ind, int chance, vector<int> &s) {
        if(ind >= s.size()) return 0;
        if(dp[ind][chance] != -1) return dp[ind][chance];
        
        int ans = chance ? INT_MIN / 2 : INT_MAX / 2;
        if(chance) {
            for(int i = ind, sum = 0; i < ind + 3 and i < s.size(); ++i) {
                sum += s[i];
                ans = max(ans, sum + dfs(i + 1, chance ^ 1, s));
            }
        } else {
            for(int i = ind; i < ind + 3 and i < s.size(); ++i) {
                ans = min(ans, dfs(i + 1, chance ^ 1, s));
            }            
        }
        
        return dp[ind][chance] = ans;
    }    
    string stoneGameIII(vector<int>& s) {
        memset(dp, -1, sizeof dp);
        int ans = dfs(0, 1, s);
        int tot = accumulate(s.begin(), s.end(), 0);
        
        if(ans * 2 == tot) return "Tie";
        if(ans * 2 > tot) return "Alice";
        return "Bob";
    }
};