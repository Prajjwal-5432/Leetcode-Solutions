//Link: https://leetcode.com/problems/stone-game-viii/
//Recursive: https://cpexplanations.blogspot.com/2021/05/1872-stone-game-viii.html
//Refer: https://leetcode.com/problems/stone-game-viii/discuss/1224658/Python-Cumulative-sums-%2B-oneliner-explained

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        partial_sum(stones.begin(), stones.end(), stones.begin());
        int res = stones.back();
        for(int i = stones.size() - 2; i > 0; --i) {
            res = max(res, stones[i] - res);
        }
        return res;
    }
};