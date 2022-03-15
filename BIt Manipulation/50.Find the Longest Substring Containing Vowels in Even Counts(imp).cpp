//Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int alpha[] = {2, 0, 0, 0, 4, 0, 0, 0, 8, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0};
        
        int curMask = 0;
        vector<int> ind(64, -1);
        
        int len = 0, n = s.length();
        for(int i = 0; i < n; ++i) {
            curMask ^= alpha[s[i] - 'a'];
            
            if(ind[curMask] == -1 and curMask != 0) ind[curMask] = i;
                
            len = max(len, i - ind[curMask]);
        }
        
        return len;
    }
};