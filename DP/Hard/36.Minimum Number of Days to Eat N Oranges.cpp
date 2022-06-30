//Link: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

struct mhash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    uint64_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define ll long long
class Solution {
public:
    unordered_map<ll, ll, mhash> dp;
    ll dfs(ll num) {
        if(num <= 1) return num;
        if(dp.count(num)) return dp[num];
        return dp[num] = 1 + min((num % 2) + dfs(num / 2), (num % 3) + dfs(num / 3));
    }
    int minDays(int n) {
        return dfs(n);
    }
};