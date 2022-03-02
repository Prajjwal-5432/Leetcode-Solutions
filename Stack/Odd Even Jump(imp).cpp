//Link: https://leetcode.com/problems/odd-even-jump/

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        map<int, int> mp;
        
        int n = arr.size();
        vector<int> odd(n, 0), even(n, 0);
        odd[n - 1] = even[n - 1] = 1;
        
        mp[arr[n - 1]] = n - 1;
        mp[INT_MIN] = 1234;
        
        for(int i = n - 2; ~i; --i) {
            auto it = mp.lower_bound(arr[i]);
            
            if(it != mp.end()) odd[i] = even[it->second];
            
            if(it == mp.end() or it->first > arr[i]) it--;
            if(it->first != INT_MIN) even[i] = odd[it->second];
            
            mp[arr[i]] = i;
        }
        
        return count(odd.begin(), odd.end(), 1);
    }
};