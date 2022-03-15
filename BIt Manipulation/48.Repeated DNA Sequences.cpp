//Link: https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10) return vector<string> ();
        
        unordered_map<string, int> mp;
        
        for(int i = 0; i < s.length() - 9; ++i) {
            mp[s.substr(i, 10)]++;
        }
        
        vector<string> seq;
        for(auto [x, y]: mp) {
            if(y > 1) seq.push_back(x);
        }
        
        return seq;
    }
};