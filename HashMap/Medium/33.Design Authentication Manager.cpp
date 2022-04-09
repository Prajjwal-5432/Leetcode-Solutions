//Link: https://leetcode.com/problems/design-authentication-manager/
//Refer leetcode votrubac's solution

class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int> mp;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(!mp.count(tokenId) or mp[tokenId] + ttl <= currentTime) return;
        mp[tokenId] = currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        
        for(auto [x, y]: mp) {
            if(y + ttl > currentTime) cnt++;
        }
        
        return cnt;
    }
};
