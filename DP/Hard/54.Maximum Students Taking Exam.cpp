//Link: https://leetcode.com/problems/maximum-students-taking-exam/

class Solution {
public:
    bool canPlace(int prev, int cur, vector<char> &v) {
        bool flag = 1;
        for(int i = 0; i < v.size(); ++i) {
            int lefbit = i - 1;
            int rigbit = i + 1;
            if(cur >> i & 1) {
                if(lefbit >= 0) flag &= !(prev >> lefbit & 1);
                if(lefbit >= 0) flag &= !(cur >> lefbit & 1);
                flag &= !(cur >> rigbit & 1);
                flag &= !(prev >> rigbit & 1);
                flag &= (v[i] != '#');
            }
        }
        return flag;
    }
    
    int dp[10][1 << 9];
    int n, m;
    int dfs(int ind, int prev, vector<vector<char>> &seats) {
        if(ind == n) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        int ans = 0;
        for(int i = 0; i < (1 << m); ++i) {
            if(canPlace(prev, i, seats[ind])) {
                ans = max(ans, __builtin_popcount(i) + dfs(ind + 1, i, seats));
            }
        }
        
        return dp[ind][prev] = ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        memset(dp, -1, sizeof dp);
        this->n = seats.size();
        this->m = seats[0].size();
        
        return dfs(0, 0, seats);
    }
};