//Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/

bool operator<= (const vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); ++i) 
        if(a[i] > b[i]) return false;
    return true;
}

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int mxScore = 0;
        
        vector<int> lettersCount(26, 0);
        for(auto x: letters) lettersCount[x - 'a']++;
        
        for(int i = 0; i < (1 << n); ++i) {
            vector<int> cnt(26, 0);
            for(int j = 0, num = i; num; ++j, num >>= 1) {
                if(num & 1) {
                    for(auto x: words[j]) cnt[x - 'a']++;
                }
            }
            
            if(cnt <= lettersCount) {
                int curScore = 0;
                for(int j = 0; j < 26; ++j) {
                    curScore += cnt[j] * score[j];
                }
                mxScore = max(mxScore, curScore);
            }
        }
        
        return mxScore;
    }
};