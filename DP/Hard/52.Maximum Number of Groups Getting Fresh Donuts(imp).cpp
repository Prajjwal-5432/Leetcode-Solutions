//Link: https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/

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
    unordered_map<long long, int, mhash> mp;
    long long hash(vector<int> &rems) {
        long long res = 0;
        for(int i = 0; i < rems.size(); ++i) {
            res = res * 37 + rems[i];
        }
        return res;
    }
    int dfs(vector<int> rems, int remainder, int k) {
        long long hval = hash(rems) * 37 + remainder;  
        if(mp.count(hval)) return mp[hval];
        
        int ans = 0;
        for(int i = 1; i < rems.size(); ++i) {
            if(rems[i] > 0) {
                rems[i]--;
                ans = max(ans, (remainder == 0) + dfs(rems, (remainder + i) % k, k));
                rems[i]++;
            }
        }
        
        return mp[hval] = ans;
    }
    int maxHappyGroups(int k, vector<int>& groups) {
        vector<int> rems(k, 0);
        int res = 0;
        for(int i = 0; i < groups.size(); ++i) {
            if(groups[i] % k == 0)
                res++;
            else
                rems[groups[i] % k]++;
        }
        
        return res + dfs(rems, 0, k);
    }
};