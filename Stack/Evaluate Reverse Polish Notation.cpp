//Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int op(int b, int a, string x) {
        if(x == "+") return b + a;
        if(x == "-") return b - a;
        if(x == "*") return b * a;
        return b / a;
    }
    int evalRPN(vector<string>& tokens) {
        vector<int> res;
        for(auto x: tokens) {
            if(x == "+" or x == "-" or x == "*" or x == "/") {
                int a = res.back(), b = res[res.size() - 2];
                res.pop_back(), res.pop_back();
                res.push_back(op(b, a, x));
            } else {
                res.push_back(stoi(x));
            }
        }
        return res.back();
    }
};