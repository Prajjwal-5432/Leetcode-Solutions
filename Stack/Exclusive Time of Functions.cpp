//Link: https://leetcode.com/problems/exclusive-time-of-functions/
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<array<int64_t, 3>> st;
        vector<int> ans(n, 0);
        
        for(int i = 0; i < logs.size(); ++i) {
            string log = logs[i];
            int x = log.find(':'), y = log.rfind(':');
            
            int id = stoi(log.substr(0, log.find(':')));
            char ch = log[x + 1];
            int64_t stamp = stoll(log.substr(y + 1));
            
            if(ch == 's') st.push_back({id, stamp, 0});
            else {
                int val = stamp - st.back()[1] + 1 - st.back()[2];
                ans[id] += val;
                int extra = st.back()[2];
                st.pop_back();
                if(!st.empty()) st.back()[2] += val + extra;
            }
        }
        
        return ans;
    }
};