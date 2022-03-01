//Link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

//The count of every numbers in a particular range in the sorted and the unsorted array should be same so for that we use map one for sorted and one for unsorted
//Secondly for that range the max and min should be equal to the sorted array individual endpoints of that range 

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        vector<int> a = arr;
        sort(a.begin(), a.end());
        
        unordered_map<int, int> x, y;
        
        int cnt = 0, l = 0, r = 0, mi = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < arr.size(); ++i) {
            x[a[i]]++, y[arr[i]]++;
            mi = min(mi, arr[i]), mx = max(mx, arr[i]);
            if(y[a[i]] == x[a[i]] and x[arr[i]] == y[arr[i]] and mx == a[r] and mi == a[l]) {
                cnt++;
                l = r = i + 1;
                mi = INT_MAX, mx = INT_MIN;
                x.clear(), y.clear();
            } else {
                r++;
            }
        }
        
        return cnt;
    }
};