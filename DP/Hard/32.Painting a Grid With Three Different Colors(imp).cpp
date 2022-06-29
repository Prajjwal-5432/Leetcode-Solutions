//Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/

#define ll long long
ll dp[1111][1LL << 11];
ll mod;
class Solution {
public:
    int n, m;
    vector<vector<int>> combos;
    vector<int> comboMask;
    
    void combinations(int ind, vector<int> &v) {
        if(ind == m) {
            combos.push_back(v);
            return;
        }
        
        for(int i = 0; i < 3; ++i) {
            if(v.empty() or v.back() != i) {
                v.push_back(i);
                combinations(ind + 1, v);
                v.pop_back();
            }
        }
    }
    
    int colToMask(vector<int> &v) {
        int mask = 0;
        
        for(int i = 2 * m - 1, j = 0; ~i; i -= 2, ++j) {
            if(v[j] == 0) continue;
            else if(v[j] == 1) mask |= (1 << (i - 1));
            else mask |= (1 << i);
        }
        
        return mask;
    }
    vector<int> maskToCol(int mask) {
        vector<int> col;
        for(int i = 2 * m - 1; i >= 0; i -= 2) {
            int zero = (mask >> (i - 1) & 1);
            int one = (mask >> i & 1);
            
            if(zero == 0 and one == 0) col.push_back(0);
            else if(zero == 1) col.push_back(1);
            else col.push_back(2);
        }
        return col;
    }
    
    ll dfs(int ind, int mask) {
        if(ind == n) return 1;
        if(dp[ind][mask] != -1) return dp[ind][mask];
        
        vector<int> col = maskToCol(mask);
        
        ll ans = 0;
        for(int i = 0; i < combos.size(); ++i) {
            bool flag = 1;
            for(int j = 0; j < col.size(); ++j) flag &= (combos[i][j] != col[j]);
            
            if(flag) {
                ans = (ans + dfs(ind + 1, comboMask[i])) % mod;
            }
        }
        
        return dp[ind][mask] = ans;
    }
    
    int colorTheGrid(int m, int n) {
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
        this->n = n;
        this->m = m;
        
        vector<int> v;
        combinations(0, v);
        for(auto x: combos) comboMask.push_back(colToMask(x));
        
        ll ans = 0;
        for(auto x: comboMask) {
            ans = (ans + dfs(1, x)) % mod;;
        }
        
        return ans;
    }
};