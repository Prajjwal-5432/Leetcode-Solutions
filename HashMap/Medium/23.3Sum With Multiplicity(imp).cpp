//Link: https://leetcode.com/problems/3sum-with-multiplicity/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long long> cnt;
        
        for(auto x: arr)
            cnt[x]++;
        
        long long res = 0;
        
        for(auto [i, _i]: cnt) {
            for(auto [j, _j]: cnt) {
                int k = target - i - j;
                
                if(!cnt.count(k)) continue;
                
                if (i == j && j == k)
                    res += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
                else if (i == j && j != k)
                    res += cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
                else if (i < j && j < k)
                    res += cnt[i] * cnt[j] * cnt[k];
            }
        }
        
        return res % 1000000007;
    }
};