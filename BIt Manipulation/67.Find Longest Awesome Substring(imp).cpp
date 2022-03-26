//Link: https://leetcode.com/problems/find-longest-awesome-substring/

class Solution {
public:
    int longestAwesome(string s) {
        vector<int> ind(1 << 10, s.length());
        ind[0] = -1;
        
        int mask = 0, ans = 0;
        
        for(int i = 0; i < s.length(); ++i) {
            mask ^= (1 << (s[i] - '0'));
            ans = max(ans, i - ind[mask]);
            
            for(int j = 0; j < 10; ++j)
                ans = max(ans, i - ind[mask ^ (1 << j)]);
            
            ind[mask] = min(ind[mask], i);
        }
        
        return ans;
    }
};