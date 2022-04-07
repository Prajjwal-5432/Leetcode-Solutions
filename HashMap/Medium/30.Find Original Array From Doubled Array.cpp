//Link: https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    const static int nx = 1e5 + 100;
    int c[nx];
    
    vector<int> findOriginalArray(vector<int>& changed) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        
        for(auto x: changed) c[x]++;
        
        if(c[0] & 1) return {};
        
        vector<int> orignal;
        
        for(int i = nx - 1; i; --i) {
            if(c[i]) {
                if(i & 1) return {};
                if(c[i / 2] < c[i]) return {};
                
                c[i / 2] -= c[i];
                for(int j = 0; j < c[i]; ++j) orignal.push_back(i / 2);
            }
        }
        for(int j = 0; j < c[0] / 2; ++j) orignal.push_back(0);
        
        return orignal;
    }
};