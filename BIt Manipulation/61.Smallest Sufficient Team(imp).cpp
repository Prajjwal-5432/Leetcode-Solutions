//Link: https://leetcode.com/problems/smallest-sufficient-team/

class Solution {
public:
    vector<int> pmask;
    int64_t dp[1 << 16];
    
    int64_t func(int mask) {
        if(mask == 0) return 0;
        if(dp[mask] != -1) return dp[mask];
        
        int64_t ans = 0;
        for(int i = 0; i < pmask.size(); ++i) {
            if(mask & pmask[i]) {
                int64_t v = func(mask & ~pmask[i]);
                v |= (1LL << i);
                
                if(ans == 0 or __builtin_popcountll(ans) > __builtin_popcountll(v)) ans = v;
            }
        }
        
        return dp[mask] = ans;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        memset(dp, -1, sizeof(dp));
        
        int skills = req_skills.size();
        
        unordered_map<string, int> mp;
        for(int i = 0; i < req_skills.size(); ++i) 
            mp[req_skills[i]] = i;
        
        int n = people.size();
        pmask.resize(n, 0);
        
        for(int i = 0; i < people.size(); ++i) 
            for(auto y: people[i]) 
                pmask[i] |= (1 << mp[y]);
        
        int64_t ans = func((1 << skills) - 1);
        
        vector<int> v;
        for(int i = 0; ans; ++i, ans >>= 1) {
            if(ans & 1) v.push_back(i);
        }
        
        return v;
    }
};