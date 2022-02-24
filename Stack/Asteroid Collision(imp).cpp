//Link: https://leetcode.com/problems/asteroid-collision/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s;
        
        for(int i = 0; i < a.size(); ++i) {
            if(s.empty()) s.push_back(a[i]);
            else {
                int sign1 = s.back() > 0 ? 1 : -1, sign2 = a[i] > 0 ? 1 : -1;
                
                if(sign1 > 0 and sign2 < 0) {
                    bool flag = 1;
                    while(!s.empty() and sign1 > 0 and sign2 < 0) {
                        if(s.back() == -a[i]) {
                            s.pop_back();
                            flag = 0;
                            break;
                        } else if(s.back() > -a[i]) {
                            flag = 0;
                            break;
                        } else {
                            s.pop_back();
                        }
                        if(!s.empty()) sign1 = s.back() > 0 ? 1 : -1;
                    }
                    if(flag) s.push_back(a[i]);
                } else {
                    s.push_back(a[i]);
                }
            }
        }
        
        return s;
    }
};