//Link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len = 0;
        unordered_map<string, int> mp;
        
        for(auto x: words) mp[x]++;
        
        int same = 2;
        for(auto [x, y]: mp) {
            string rev = x;
            swap(rev[0], rev[1]);
            
            if(x[0] == x[1]) {
                if(y & 1) {
                    len += 2 * (y - 1);
                    len += same;
                    same = 0;
                } else {
                    len += 2 * y;
                }
            } else {
                if(mp.count(rev)) {
                    int mn = min(y, mp[rev]);
                    len += 4 * mn;
                    
                    mp[x] -= mn;
                    mp[rev] -= mn;
                }
            }
        }
        
        return len;
    }
};