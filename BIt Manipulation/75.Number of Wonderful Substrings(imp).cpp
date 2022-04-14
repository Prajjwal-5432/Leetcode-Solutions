//Link: https://leetcode.com/problems/number-of-wonderful-substrings/

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        
        long long mask = 0, res = 0;
        
        for(int i = 0; i < word.length(); ++i) {
            mask ^= (1 << (word[i] - 'a'));
            
            res += cnt[mask];
            
            for(int j = 0; j < 10; ++j) {
                res += cnt[mask ^ (1LL << j)];
            }
            cnt[mask]++;
        }
        
        return res;
    }
};