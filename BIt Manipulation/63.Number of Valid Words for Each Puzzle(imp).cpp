//Link: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
//Refer: leetcode's solution

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mp;
        
        for(auto x: words) {
            int mask = 0;
            for(auto y: x) mask |= (1 << (y - 'a'));
            mp[mask]++;
        }
        
        int n = puzzles.size();
        vector<int> ans;
        
        for(auto x: puzzles) {
            int mask = 0;
            for(auto y: x) mask |= (1 << (y - 'a'));
            
            int first = 1 << (x[0] - 'a'), cnt = 0;
            
            for(int sub = mask; sub; sub = (sub - 1) & mask) {
                if((sub & first) == first) cnt += mp[sub];
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};