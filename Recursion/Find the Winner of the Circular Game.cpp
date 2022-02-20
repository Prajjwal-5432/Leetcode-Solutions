//Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for(int i = 2; i < n + 1; i++) res = (res + k) % i;
        return res + 1;
    }
};