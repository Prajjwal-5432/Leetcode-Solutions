//Link: https://leetcode.com/problems/sum-of-subarray-ranges/
//Refer to the question: https://leetcode.com/problems/sum-of-subarray-minimums/
class Solution {
public:
    long long subArrayRanges(vector<int>& a) {
        int n = a.size();
        
        long long add = 0, sub = 0;
        
        vector<int> lr(n, n), rl(n, -1);
        vector<int> v, s;
        
        for(int i = 0; i < n; ++i) {
            while(!v.empty() and a[i] <= a[v.back()]) {
                lr[v.back()] = i;
                v.pop_back();
            }
            v.push_back(i);
            while(!s.empty() and a[n - i - 1] < a[s.back()]) {
                rl[s.back()] = n - i - 1;
                s.pop_back();
            }
            s.push_back(n - i - 1);
        }
        
        for(int i = 0; i < n; ++i) sub += a[i] * (1LL * (lr[i] - i) * (i - rl[i]));
        
        lr.assign(n, n), rl.assign(n, -1);
        s.clear(), v.clear();
        
        for(int i = 0; i < n; ++i) {
            while(!v.empty() and a[i] >= a[v.back()]) {
                lr[v.back()] = i;
                v.pop_back();
            }
            v.push_back(i);
            while(!s.empty() and a[n - i - 1] > a[s.back()]) {
                rl[s.back()] = n - i - 1;
                s.pop_back();
            }
            s.push_back(n - i - 1);
        }
        
        for(int i = 0; i < n; ++i) add += a[i] * (1LL * (lr[i] - i) * (i - rl[i]));
        
        return add - sub;
    }
};