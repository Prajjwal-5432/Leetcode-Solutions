//Link: https://leetcode.com/problems/random-flip-matrix/

class Solution {
public:
    deque<pair<int, int>> ind, del;
    Solution(int m, int n) {
        for(int i = 0; i < min(m, 1001); ++i) {
            for(int j = 0; j < min(n, 1001); ++j) {
                ind.push_back({i, j});
            }
        }
    }
    
    vector<int> flip() {
        int x = ind.back().first, y = ind.back().second;
        del.push_back(ind.back());
        ind.pop_back();
        return {x, y};
    }
    
    void reset() {
        for(auto x: del) ind.push_front(x);
        del.clear();
    }
};