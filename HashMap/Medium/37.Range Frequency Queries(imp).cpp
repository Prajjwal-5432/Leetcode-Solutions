//Link: https://leetcode.com/problems/range-frequency-queries/

class RangeFreqQuery {
public:
    map<int, vector<int>> mp;
    
    RangeFreqQuery(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        for(int i = 0; i < arr.size(); ++i) {
            mp[arr[i]].push_back(i);
        }    
    }
    
    int query(int left, int right, int value) {
        int l = lower_bound(mp[value].begin(), mp[value].end(), left) - mp[value].begin();
        int r = upper_bound(mp[value].begin(), mp[value].end(), right) - mp[value].begin();
        
        if(l == mp[value].size()) return 0;
        
        return r - l;
    }
};
