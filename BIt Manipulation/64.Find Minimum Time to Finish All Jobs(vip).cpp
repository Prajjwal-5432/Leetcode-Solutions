//Link: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
//Note: whenever min of max or max of min is asked think binary search

class Solution {
public:
    bool func(int ind, int target, vector<int> jobs, vector<int> workers) {
        if(ind == jobs.size()) return true;
        
        for(int i = 0; i < workers.size(); ++i) {
            if(workers[i] + jobs[ind] <= target) {
                workers[i] += jobs[ind];
                
                if(func(ind + 1, target, jobs, workers)) return true;
                
                workers[i] -= jobs[ind];
            }
            if(!workers[i]) break;
        }
        
        return false;
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        
        int lo = jobs.front();
        int ans = lo;
        int hi = accumulate(jobs.begin(), jobs.end(), 0);
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(func(0, mid, jobs, vector<int> (k, 0))) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};