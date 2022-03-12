//Link: https://leetcode.com/problems/maximum-compatibility-score-sum/
//2D dp is not required cuz at any index the no of students and no of mentors will be the same but the bit position may be diffrent

class Solution {
public:
    vector<int> st, mt;
    int n, m;
    int dp[1 << 9];
    vector<int> convert(vector<vector<int>> mat) {
        vector<int> v;
        for(auto x: mat) {
            int num = 0;
            reverse(x.begin(), x.end());
            for(int i = 0; i < x.size(); ++i) {
                if(x[i]) num |= (1 << i);
            }
            v.push_back(num);
        }
        
        return v;
    }
    
    int fun(int idx, int mask) {
        if(idx == n) return 0;
        if(dp[mask] != -1) return dp[mask];
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) continue;
            
            int score = m - __builtin_popcount(st[idx] ^ mt[i]);
            ans = max(ans, score + fun(idx + 1, mask | (1 << i)));
        } 
        
        return dp[mask] = ans;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        st = convert(students);
        mt = convert(mentors);
        n = students.size();
        m = students[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        return fun(0, 0);
    }
};