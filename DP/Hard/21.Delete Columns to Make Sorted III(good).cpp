//Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/

class Solution {
public:
    bool check(vector<string>& strs, int i, int j) {
        bool flag = 1;
        for(auto x: strs) {
            flag &= (x[i] >= x[j]);
            if(flag == 0) return flag;
        }
        return flag;
    }

    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        
        vector<int> dp(n, 1);
        
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(check(strs, i, j)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        return n - mx;
    }
};