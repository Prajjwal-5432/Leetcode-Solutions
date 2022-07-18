//Link: https://leetcode.com/problems/count-ways-to-make-array-with-product/

const int mod = 1e9 + 7;
const int nx = 1e4 + 10;

int combo[nx][16];
bool flag = 0;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 
                19, 23, 29, 31, 37, 41,
                43, 47, 53, 59, 61, 67, 
                71, 73, 79, 83, 89, 97};

class Solution {
public:
    int ncr(int n, int r) {
        if(r == 0 or r == n) return 1;
        if(r == 1) return n;
        if(combo[n][r] != -1) return combo[n][r];
        return combo[n][r] = (ncr(n - 1, r) + ncr(n - 1, r - 1)) % mod;
    }
    vector<int> waysToFillArray(vector<vector<int>>& q) {
        if(flag == false) memset(combo, -1, sizeof combo);
        
        int n = q.size();
        vector<int> res(n, 1);
        for(int i = 0; i < n; ++i) {
            int len = q[i][0], k = q[i][1];
            
            for(auto x: primes) {
                int r = 0;
                while(k % x == 0) {
                    k /= x;
                    r++;
                }
                res[i] = (1ll * res[i] % mod * ncr(r + len - 1, r) % mod) % mod;
            }
            if(k > 1) res[i] = (1ll * res[i] * len) % mod;
        }
        
        return res;
    }
};