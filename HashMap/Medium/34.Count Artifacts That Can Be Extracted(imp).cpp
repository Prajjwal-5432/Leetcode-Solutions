//Link: https://leetcode.com/problems/count-artifacts-that-can-be-extracted/

class Solution {
public:
    const static int nx = 1e3 + 10;
    bool vis[nx][nx];
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        
        for(auto x: dig) {
            vis[x[0]][x[1]] = 1;
        }
        
        int cnt = 0;
        for(auto x: artifacts) {
            bool flag = 1;
            for(int i = x[0]; i < x[2] + 1; ++i) for(int j = x[1]; j < x[3] + 1; ++j) {
                flag &= vis[i][j];
            }
            cnt += flag;
        }
        
        return cnt;
    }
};