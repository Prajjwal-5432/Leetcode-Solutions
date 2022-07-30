//Link: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
class Solution {
public:
    int len, dp[22][3];
    vector<int> cur;
    long long dfs(int ind, int gr, vector<string> &digits) {
        if(ind == len) return 1;
        if(dp[ind][gr] != -1) return dp[ind][gr];
        long long ans = 0;
        for(auto x: digits) {
            int num = stoi(x);
            if(num < cur[ind])
                ans += dfs(ind + 1, 0, digits);
            else if(num == cur[ind])
                ans += dfs(ind + 1, gr & 1, digits);
            else if(gr == 0)
                ans += dfs(ind + 1, gr, digits);
        }
        
        return dp[ind][gr] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        while(n > 0) {
            cur.push_back(n % 10);
            n /= 10;
        }
        reverse(cur.begin(), cur.end());
        len = cur.size();
        
        memset(dp, -1, sizeof dp);
        long long ans = dfs(0, 1, digits);
        
        long long cnt = 0;
        for(int i = 1; i < len; ++i) {
            cnt += power(digits.size(), i);
        }
        return ans + cnt;
    }
    long long power(long long a, long long n) {
        long long ret = 1;
        long long mod = 1e9 + 7;
        while (n > 0) {
            if (n & 1) ret = ret * a;
            a = a * a;
            n >>= 1;
        }
        return ret;
    }
};