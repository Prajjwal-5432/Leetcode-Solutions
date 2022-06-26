//Link: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/

int dp[333][28][28];
int cost[26][26];

class Solution {
public:
    string s;
    int dfs(int ind, int f1, int f2) {
        if(ind == s.length()) return 0;
        if(dp[ind][f1][f2] != -1) return dp[ind][f1][f2];
        
        int ans = INT_MAX / 2;
        ans = min(ans, cost[f1][s[ind] - 'A'] + dfs(ind + 1, s[ind] - 'A', f2));
        ans = min(ans, cost[f2][s[ind] - 'A'] + dfs(ind + 1, f1, s[ind] - 'A'));
        
        return dp[ind][f1][f2] = ans;
    }
    int minimumDistance(string word) {
        unordered_map<char, array<int, 2>> mp;
        
        char x = 'A';
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 6; ++j) {
                mp[x++] = {i, j};        
            }
        }
        mp['Y'] = {4, 0}, mp['Z'] = {4, 1};
        
        for(int i = 0; i < 26; ++i) for(int j = 0; j < 26; ++j) {
            cost[i][j] = abs(mp[char(i + 'A')][0] - mp[char(j + 'A')][0]) +
                         abs(mp[char(i + 'A')][1] - mp[char(j + 'A')][1]);
        }
        
        memset(dp, -1, sizeof dp);
        this->s = word;
        
        int ans = INT_MAX / 2;
        for(int i = 0; i < 26; ++i) for(int j = 0; j < 26; ++j) {
            ans = min(ans, dfs(0, i, j));
        }
        
        return ans;
    }
};