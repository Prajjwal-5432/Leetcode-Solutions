//Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

class Solution {
public:
    int beautySum(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        
        vector<vector<int>> pre(26, vector<int> (s.length() + 1 , 0));
        
        for(char x = 'a'; x <= 'z'; ++x) {
            for(int i = 0; i < s.length(); ++i)
                pre[x - 'a'][i + 1] = pre[x - 'a'][i] + (s[i] == x);
        }
        
        int beauty = 0;
        for(int i = 0; i < s.length(); ++i) {
            for(int j = i; j < s.length(); ++j) {
                int mx = INT_MIN, mn = INT_MAX;
                for(char x = 'a'; x <= 'z'; ++x) {
                    int cnt = pre[x - 'a'][j + 1] - pre[x - 'a'][i];
                    mx = max(mx, cnt);
                    if(cnt) mn = min(mn, cnt);
                }
                
                if(mn != INT_MAX)
                    beauty += mx - mn;
            }
        }
        
        return beauty;
    }
};