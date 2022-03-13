//Link: https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/

class Solution {
public:
    long convert(string s) {
        long num = 0;
        for(auto x: s) num |= (1 << (x - 'a'));
        return num;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        map<int, unordered_set<int>> mp;
        
        for(auto x: startWords) mp[x.size()].insert(convert(x));
        
        int cnt = 0;
        for(auto x: targetWords) {
            for(int i = 0; i < x.length(); ++i) {
                string s = x.substr(0, i) + x.substr(i + 1);
                if(mp[x.size() - 1].count(convert(s))) {
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};