//Link: https://leetcode.com/problems/can-convert-string-in-k-moves/

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length()) return 0;
        
        int n = s.length();
        
        unordered_map<int, int> mp;
        for(int i = 0; i < 28; ++i) mp[i] = i;
        
        for(int i = 0; i < n; ++i) {
            if(s[i] == t[i]) continue;
            
            int dis = (s[i] < t[i] ? t[i] - s[i] : 26 - (s[i] - t[i]));
            
            if(mp[dis] <= k) mp[dis] += 26;
            else return 0;
        }
        
        return 1;
    }
};