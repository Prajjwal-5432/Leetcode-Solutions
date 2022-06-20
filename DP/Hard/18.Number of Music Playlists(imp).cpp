//Link: https://leetcode.com/problems/number-of-music-playlists/

#define ll long long
ll dp[111][222];
ll mod;

class Solution {
public:
    Solution() {
        memset(dp, -1, sizeof dp);
        mod = 1e9 + 7;
    }
    int numMusicPlaylists(int n, int goal, int k, int song = 0, int diff = 0) {
        if(song == goal) return diff == n;
        if(dp[song][diff] != -1) return dp[song][diff];
        
        ll res = numMusicPlaylists(n, goal, k, song + 1, diff + 1) % mod * (n - diff) % mod;
        res = (res + numMusicPlaylists(n, goal, k, song + 1, diff) % mod * max(diff - k, 0) % mod) % mod;
        
        return dp[song][diff] = res;
    }
};