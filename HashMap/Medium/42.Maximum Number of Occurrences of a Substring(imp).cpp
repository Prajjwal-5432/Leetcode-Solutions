//Link: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        if(s.length() < minSize) return 0;
        
        unordered_map<string, int> mp;
        unordered_map<char, int> cnt;
        
        for(int i = 0; i < minSize - 1; ++i) cnt[s[i]]++;
        
        int l = 0;
        for(int i = minSize - 1; i < s.length(); ++i) {
            cnt[s[i]]++;
            
            while(cnt.size() > maxLetters or i - l + 1 > minSize) {
                cnt[s[l]]--;
                if(cnt[s[l]] == 0) cnt.erase(s[l]);
                l++;
            }
            if(i - l + 1 >= minSize and i - l + 1 <= maxSize and cnt.size() <= maxLetters) {
                mp[s.substr(l, i - l + 1)]++;
            }
        }
        
        int mx = 0;
        for(auto [x, y]: mp) mx = max(mx, y);
        
        return mx;
    }
};