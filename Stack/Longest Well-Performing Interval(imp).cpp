//Link: https://leetcode.com/problems/longest-well-performing-interval/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> mp;
        int pre = 0, ans = 0;
        
        for(int i = 0; i < hours.size(); ++i) {
            pre += hours[i] > 8 ? 1 : -1;
            if(pre > 0) ans = i + 1;
            else if(mp.count(pre - 1)) ans = max(ans, i - mp[pre - 1]);
            
            if(!mp.count(pre)) mp[pre] = i;
        }
        
        return ans;
    }
};