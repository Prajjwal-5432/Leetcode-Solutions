//Link: https://leetcode.com/problems/remove-boxes/

const int nx = 222;
int dp[nx][nx][nx];

class Solution {
public:
    int func(vector<int>& boxes, int i, int j, int k) {
        if(i > j) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        int iorg = i, korg = k;
        while(i + 1 <= j and boxes[i] == boxes[i + 1]) i++, k++;
        
        int res = (k + 1) * (k + 1) + func(boxes, i + 1, j, 0);
        
        for(int m = i + 1; m <= j; ++m) {
            if(boxes[i] == boxes[m]) 
                res = max(res, func(boxes, i + 1, m - 1, 0) + func(boxes, m, j, k + 1));
        } 
        
        return dp[iorg][j][korg] = res;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof dp);
        return func(boxes, 0, boxes.size() - 1, 0);
    }
};