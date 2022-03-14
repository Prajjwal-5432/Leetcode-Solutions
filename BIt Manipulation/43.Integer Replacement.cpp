//Link: https://leetcode.com/problems/integer-replacement/

class Solution {
public:
    int integerReplacement(long res) {
        int steps = 0;
        
        while(res != 1) {
            if(res % 2 == 0) res /= 2;
            else if(res == 3) {
                steps += 2;
                break;
            } else if(res % 4 == 1) {
                res--;
            } else if(res % 4 == 3) {
                res++;
            }
            steps++;
        }
        
        return steps;
    }
};