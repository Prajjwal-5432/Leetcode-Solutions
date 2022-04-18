//Link: https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/

class Solution {
public:
    string getRatio(int a, int b) {
        int x = __gcd(a, b);
        a /= x, b /= x;
        return to_string(a) + "." + to_string(b);
    }
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string, int> mp;
        
        long long cnt = 0;
        for(int i = 0; i < rectangles.size(); ++i) {
            string ratio = getRatio(rectangles[i][0], rectangles[i][1]);
            
            cnt += mp[ratio];
            mp[ratio]++;
        }
        
        return cnt;
    }
};