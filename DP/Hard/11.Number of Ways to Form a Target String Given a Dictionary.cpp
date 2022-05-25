#define ll long long
const int nx = 1e3 + 10;
int freq[26][nx];
ll dp[nx][nx];
ll mod;

class Solution {
public:
    int n, m;
    string target;
    
    ll func(int ind, int curind) {
        if(ind == n) return 1;
        if(curind == m) return 0;
        if(dp[ind][curind] != -1) return dp[ind][curind];
        
        ll ans = 0, frequency = freq[target[ind] - 'a'][curind];
        ans = (frequency * func(ind + 1, curind + 1)) % mod;
        ans = (ans + func(ind, curind + 1)) % mod;
        
        return dp[ind][curind] = ans;
    }
    
    int numWays(vector<string>& words, string target) {
        memset(dp, -1, sizeof dp);
        memset(freq, 0, sizeof freq);
        mod = 1e9 + 7;
        
        this->n = target.length();
        this->m = words[0].length();
        this->target = target;
        
        for(int i = 0; i < words.size(); ++i) {
            for(int j = 0; j < words[i].length(); ++j) {
                freq[words[i][j] - 'a'][j]++;
            }
        }
        
        return func(0, 0);
    }
};