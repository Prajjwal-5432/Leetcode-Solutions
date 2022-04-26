//Link: https://leetcode.com/problems/random-pick-with-blacklist/

class Solution {
public:
    deque<int> random;
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> st(blacklist.begin(), blacklist.end());
        
        for(int i = 0; random.size() <= 20000 and i < n; ++i)
            if(!st.count(i))
                random.push_back(i);
    }
    
    int pick() {
        random.push_front(random.back());
        random.pop_back();
        
        return random.front();
    }
};