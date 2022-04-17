//Link: https://leetcode.com/problems/super-ugly-number/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> v(n), val(primes.size(), 1), ind(primes.size(), 0);
        
        long next = 1;
        for(int i = 0; i < n; ++i) {
            v[i] = next;
            
            next = INT_MAX;
            for(int j = 0; j < primes.size(); ++j) {
                if(val[j] == v[i]) val[j] = v[ind[j]++] * primes[j];
                next = min(next, val[j]);
            }
        }
        
        return v[n - 1];
    }
}; 