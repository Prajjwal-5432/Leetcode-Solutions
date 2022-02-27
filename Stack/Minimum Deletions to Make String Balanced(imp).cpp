//Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
//For every split point find no of deletions required
//But also consider the case if we delete either every a or every b(line No: 10)
class Solution {
public:
    int minimumDeletions(string s) {
        int a = count(s.begin(), s.end(), 'a');
        int b = s.length() - a;
        
        int deletions = min(a, b), cnta = 0, cntb = 0;
        for(int i = 0; i < s.length(); ++i) {
            a -= s[i] == 'a', b -= s[i] == 'b';
            cnta += s[i] == 'a', cntb += s[i] == 'b';
            
            deletions = min(deletions, cntb + a);
        }
        
        return deletions;
    }
};