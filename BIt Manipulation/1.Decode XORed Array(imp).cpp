//Link: https://leetcode.com/problems/decode-xored-array/

//A[i] = res[i] ^ res[i+1]
//A[i] ^ A[i] ^ res[i+1] = res[i] ^ res[i+1] ^ A[i] ^ res[i+1]
//res[i+1] = res[i] ^ A[i]

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        
        ans.push_back(first);
        
        for(auto x: encoded) {
            ans.push_back(ans.back() ^ x);
        }
        
        return ans;
    }
};

//2nd solution buid the next number bit by bit

/*
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        
        ans.push_back(first);
        
        for(auto x: encoded) {
            int number = 0;
            for(int i = 0; i < 32; ++i) {
                int curbit = first & (1 << i);
                int nexbit = x & (1 << i);
                
                if(nexbit == 0) {
                    number |= curbit;
                } else {
                    if(curbit == 0) number |= (1 << i);
                    else if(curbit == 1) number &= ~(1 << i);
                }
            }
            ans.push_back(number);
            first = number;
        }
        return ans;
    }
};
*/