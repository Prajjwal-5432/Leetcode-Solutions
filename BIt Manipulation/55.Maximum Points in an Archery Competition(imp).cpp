//Link: https://leetcode.com/problems/maximum-points-in-an-archery-competition/

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        vector<int> bobArrows(12);
        int mxscore = 0;
        
        for(int i = 0; i < (1 << 12); ++i) {
            int arrows = numArrows, flag = 1, score = 0;
            vector<int> curArrows(12);
            
            for(int j = 0, num = i; num; ++j, num >>= 1) {
                if(num & 1) {
                    if(arrows > aliceArrows[j]) {
                        curArrows[j] = aliceArrows[j] + 1;
                        arrows -= (aliceArrows[j] + 1);
                        score += j;
                    } else {
                        flag = 0;
                    }        
                }
            }
            
            if(score > mxscore and flag) {
                curArrows[0] += arrows; //adding remaining arrows to any of the arrows
                bobArrows = curArrows;
                mxscore = score;
            }
        }
        
        return bobArrows;
    }
};