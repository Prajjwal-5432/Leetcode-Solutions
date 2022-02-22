//Link: https://leetcode.com/problems/validate-stack-sequences/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        vector<int> v;
        
        reverse(popped.begin(), popped.end());
        
        for(int i = 0; i < pushed.size(); ++i) {
            v.push_back(pushed[i]);
            while(!v.empty() and !popped.empty() and v.back() == popped.back()) {
                v.pop_back();
                popped.pop_back();
            }
        }
        
        return v.empty();
    }
};