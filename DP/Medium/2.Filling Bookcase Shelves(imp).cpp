//Link: https://leetcode.com/problems/filling-bookcase-shelves/

class Solution {
public:
    #define min(a, b) a < b ? a : b
    
    const static int nx = 1e3 + 100;
    
    int dp[nx];
    int sw;
    vector<vector<int>> books;
    
    long func(int ind) {
        if(ind >= books.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        long ans = INT_MAX;
        int mx = 0, tw = 0;
        
        for(int i = ind; i < books.size(); ++i) {
            mx = max(mx, books[i][1]);
            tw += books[i][0];
            
            if(tw <= sw)
                ans = min(ans, mx + func(i + 1));
            else
                break;
        }
        
        return dp[ind] = ans;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        this->books = books;
        sw = shelfWidth;
        
        memset(dp, -1, sizeof dp);
        
        return func(0);
    }
};