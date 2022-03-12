//Link: https://leetcode.com/problems/decode-xored-permutation/

// finding the first number
// e[0] = p[0] ^ p[1]
// e[0] ^ p[1] = p[0]
// e[0] ^ p[1] ^ (p[2] ^ p[3] ^ p[4]) = p[0] ^ (p[2] ^ p[3] ^ p[4])
// e[0] ^ e[1] ^ e[3] = p[0] ^ (p[2] ^ p[3] ^ p[4])
// e[0] ^ e[1] ^ e[3] ^ (p[0] ^ p[1]) = p[0] ^ ((p[0] ^ p[1]) ^ (p[2] ^ p[3] ^ p[4]))
// e[0] ^ e[1] ^ e[3] ^ e[0] = p[0] ^ (p[0] ^ p[1] ^ p[2] ^ p[3] ^ p[4])
// e[1] ^ e[3] = p[0] ^ x
// e[1] ^ e[3] ^ x = p[0]

// let p[0] ^ p[1] ^ p[2] ^ ... ^ p[n] = x (it is a permutation from 1 to n)

// now for finding the successive numbers

// e[i] = p[i] ^ p[i + 1]
// e[i] ^ e[i] ^ p[i + 1] = p[i] ^ p[i + 1] ^ e[i] ^ p[i + 1]
// p[i + 1] = p[i] ^ e[i] 

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n = encoded.size() + 1;
        
        int x = 0;
        for(int i = 1; i < n + 1; ++i) x ^= i;
        
        for(int i = 1; i < n; i += 2) x ^= encoded[i];
        
        vector<int> ans({x});
        
        for(auto y: encoded) ans.push_back(ans.back() ^ y);
        
        return ans;
    }
};