//Link: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int len = requests.size();
        
        int mx = 0;
        for(int i = 0; i < (1 << len); ++i) {
            int bits = __builtin_popcount(i);
            if(bits <= mx) continue;
            
            vector<int> change(n, 0);
            for(int j = 0, num = i; num; ++j, num >>= 1) {
                if(num & 1) 
                    change[requests[j][0]]--, change[requests[j][1]]++;
            }
            
            if(count(change.begin(), change.end(), 0) == n)
                mx = max(mx, bits);
        }
        
        return mx;
    }
};