//Link: https://leetcode.com/problems/vowels-of-all-substrings/

class Solution {
public:
    long long countVowels(string word) {
        long long cnt = 0;
        for(int i = 0; i < word.length(); ++i) {
            if(string("aeiou").find(word[i]) != string::npos) {
                cnt += (i + 1) * (word.length() - i);
            }
        }
        return cnt;
    }
};