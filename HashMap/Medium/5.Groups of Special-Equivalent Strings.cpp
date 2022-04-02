//Link: https://leetcode.com/problems/groups-of-special-equivalent-strings/

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        unordered_set<string> groups;
        
        for(auto x: words) {
            vector<int> ev(26, 0), od(26, 0);
            for(int i = 0; i < x.size(); ++i) {
                if(i & 1) ev[x[i] - 'a']++;
                else od[x[i] - 'a']++;
            }
            
            string key;
            for(int i = 0; i < 26; ++i) {
                key += char(i + 'a') + to_string(ev[i]) + char(i + 'a') + to_string(od[i]);
            }
            
            groups.insert(key);
        }
        
        return groups.size();
    }
};