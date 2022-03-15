//Link: https://leetcode.com/problems/bitwise-ors-of-subarrays/
//Refer: https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/165881/C%2B%2BJavaPython-O(30N)
//Also checkout the vector solution

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) { 
        unordered_set<int> s, cur;
        
        for(auto x: arr) {
            unordered_set<int> t({x});
            for(auto y: cur) t.insert(x | y);
            
            cur = t;
            for(auto y: cur) s.insert(y);
        }
        
        return s.size();
    }
};