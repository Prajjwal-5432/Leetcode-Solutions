//Link: https://leetcode.com/problems/interleaving-string/
//We don't need K as the third state cuz it will always be diffrent for any pair of i and j

const int nx = 210;
int dp[nx][nx];

class Solution {
public:
    string s1, s2, s3;
    
    bool func(int i, int j, int k) {
        if(k >= s3.length()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool ans = 0;
        if(i < s1.length() and s1[i] == s3[k])
            ans |= func(i + 1, j, k + 1);
        if(j < s2.length() and s2[j] == s3[k])
            ans |= func(i, j + 1, k + 1);
        
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return 0;
        
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        memset(dp, -1, sizeof dp);
        
        return func(0, 0, 0);
    }
};