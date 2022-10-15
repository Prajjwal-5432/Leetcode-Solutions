//Link: https://leetcode.com/problems/make-array-strictly-increasing/

#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
class Solution {
public:
    int dp[2222][2222][2];
    int index(int val, int start, vector<int> &arr) {
        int lo = start, hi = arr.size() - 1, ind = arr.size();
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] > val) ind = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        return ind;
    }
    int dfs(int i, int j, int k, vector<int> &arr1, vector<int> &arr2) {
        if(i >= arr1.size()) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        int res = INT_MAX / 2;
        if(k == 0) {
            if(arr1[i] > arr1[i - 1]) res = min(res, dfs(i + 1, j, k, arr1, arr2));
            
            int ind = index(arr1[i - 1], j, arr2);
            if(ind < arr2.size()) res = min(res, 1 + dfs(i + 1, ind, 1, arr1, arr2));
        } else {
            if(arr1[i] > arr2[j]) res = min(res, dfs(i + 1, j + 1, 0, arr1, arr2));
            
            int ind = index(arr2[j], j + 1, arr2);
            if(ind < arr2.size()) res = min(res, 1 + dfs(i + 1, ind, 1, arr1, arr2));
        }
        return dp[i][j][k] = res;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort_unique(arr2);
        memset(dp, -1, sizeof dp);
        arr1.insert(arr1.begin(), -1);
        int res = dfs(1, 0, 0, arr1, arr2);
        return res == INT_MAX / 2 ? -1 : res;
    }
};