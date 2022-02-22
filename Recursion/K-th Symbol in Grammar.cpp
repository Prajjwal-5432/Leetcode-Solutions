//Link: https://leetcode.com/problems/k-th-symbol-in-grammar/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        return kthGrammar(n - 1, (k + 1) / 2) ? (k & 1 ? 1 : 0) : (k & 1 ? 0 : 1);
    }
};