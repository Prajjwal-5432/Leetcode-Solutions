//Link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
//Refer to the map solution too

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
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        unordered_map<int, vector<int>, mhash> idx;
        
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; ++i)
            idx[nums[i]].push_back(i);
        
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                long long prev = 2LL * nums[j] - nums[i];
                
                if(prev > INT_MAX or prev < INT_MIN)
                    continue;
                
                auto it = idx.find(prev);
                
                if(it != idx.end()) {
                    for(auto x: it->second) {
                        if(x >= j) break;
                        dp[i][j] += dp[j][x] + 1;
                    }
                }
                ans += dp[i][j];
            }
        }
        
        return ans;
    }
};