//Link: https://leetcode.com/problems/prison-cells-after-n-days/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_set<int> st;
        vector<int> states;
        
        while(true) {
            vector<int> nxtState(8, 0);
            
            for(int i = 1; i < 7; ++i) nxtState[i] = cells[i - 1] == cells[i + 1];
            
            int num = 0;
            for(int i = 1; i < 7; ++i) {
                if(nxtState[i]) num |= (1 << (8 - i - 1));
            }
            
            if(st.count(num)) break;
            
            st.insert(num);
            states.push_back(num);
            cells = nxtState;
        }
        
        int num = states[(n - 1) % states.size()];
        
        vector<int> state(8, 0);
        
        for(int i = 0; i < 8; ++i) state[8 - i - 1] = ((num >> i) & 1);
        
        return state;
    }
};