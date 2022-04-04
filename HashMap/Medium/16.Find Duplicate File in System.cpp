//Link: https://leetcode.com/problems/find-duplicate-file-in-system/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: paths) {
            string t, root;
            stringstream ss(x);
            
            getline(ss, root, ' ');
            while(getline(ss, t, ' ')) {
                int l = t.find('('), r = t.rfind(')');
                
                mp[t.substr(l + 1, r - l - 1)].push_back(root + "/" + t.substr(0, l));
            }
        }
        
        vector<vector<string>> ans;
        for(auto [x, y]: mp)
            if(y.size() > 1)
                ans.push_back(y);
        
        return ans;
    }
};