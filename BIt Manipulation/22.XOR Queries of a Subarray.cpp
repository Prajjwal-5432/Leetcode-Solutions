//Link: https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n = arr.size(), m = queries.size();
        vector<int> pre(n + 1), ans(m);
        
        for(int i = 0; i < n; ++i) pre[i + 1] = pre[i] ^ arr[i];
        
        for(int i = 0; i < m; ++i) ans[i] = pre[queries[i][1] + 1] ^ pre[queries[i][0]];
        
        return ans;
    }
};