//Link: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

void operator+= (vector<int> &a, vector<int> & b) {
    for(int i = 0; i < a.size(); ++i)
        a[i] += b[i];
}
class Solution {
public:
    const static int nx = 1e5 + 10;
    
    string labels;
    vector<int> graf[nx];
    bool vis[nx];
    vector<int> ans;
    
    vector<int> dfs(int v) {
        vis[v] = 1;
        vector<int> cnt(26, 0);
        
        cnt[labels[v] - 'a']++;
        
        for(auto u: graf[v]) {
            if(!vis[u]) {
                vector<int> sub = dfs(u);
                cnt += sub;
            }
        }
        
        ans[v] = cnt[labels[v] - 'a'];
        
        return cnt;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        
        this->labels = labels;    
        
        ans.resize(n);
        
        for(auto x: edges) {
            graf[x[0]].push_back(x[1]);
            graf[x[1]].push_back(x[0]);
        }
        
        auto vec = dfs(0);
        
        return ans;
    }
};