//Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> v;
        for(auto x: arr) {
            long num = 0;
            unordered_set<char> st;
            
            for(auto y: x) {
                num |= (1 << (y - 'a'));
                st.insert(y);
            }
            
            if(st.size() == x.length()) v.push_back(num);
        }
        
        int mx = 0, n = v.size();
        for(int i = 0; i < (1 << n); ++i) {
            int num = i, len = 0, flag = 1;
            long mask = 0;
            for(int j = 0; num; ++j, num >>= 1) {
                if(num & 1) {
                    if(__builtin_popcountl(mask ^ v[j]) == __builtin_popcountl(mask) + __builtin_popcountl(v[j])) {
                        len += __builtin_popcountl(v[j]);
                        mask ^= v[j];
                    } else {
                        flag = 0;
                        break;
                    }
                }
            }
            
            if(flag) mx = max(mx, len);
        }
        
        return mx;
    }
};