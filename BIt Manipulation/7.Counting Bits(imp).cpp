//Link: https://leetcode.com/problems/counting-bits/
//Refer: https://leetcode.com/problems/counting-bits/discuss/1808016/C%2B%2B-oror-Vectors-Only-oror-Easy-To-Understand-oror-Full-Explanation

class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> dp(n + 1);
       dp[0] = 0;

       for(int i = 1; i <= n; ++i) dp[i] = dp[i / 2] + (i % 2);
       return dp;
    }
};