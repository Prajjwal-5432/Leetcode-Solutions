//Link: https://leetcode.com/problems/find-good-days-to-rob-the-bank/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        
        vector<int> lr(n, 0), rl(n, 0);
        
        for(int i = 1; i < n; ++i) {
            if(security[i] <= security[i - 1])
                lr[i] += 1 + lr[i - 1];
            else
                lr[i] = 0;
        }
        for(int i = n - 2; ~i; --i) {
            if(security[i] <= security[i + 1])
                rl[i] += 1 + rl[i + 1];
            else
                rl[i] = 0;
        }
        
        vector<int> days;
        for(int i = 0; i < n; ++i) {
            if(time <= min(lr[i], rl[i]))
                days.push_back(i);
        }
        
        return days;
    }
};