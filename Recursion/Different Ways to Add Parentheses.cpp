//Link: https://leetcode.com/problems/different-ways-to-add-parentheses/
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        if(expression.length() <= 2) {
            return vector<int> ({stoi(expression)});
        }
        
        vector<int> vals;
        for(int i = 0; i < expression.length(); ++i) {
            if(expression[i] >= '0' and expression[i] <= '9') continue;
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            
            switch(expression[i]) {
                case '+':
                    for(auto x: left) for(auto y: right) vals.push_back(x + y);
                    break;
                case '-':
                    for(auto x: left) for(auto y: right) vals.push_back(x - y);
                    break;
                case '*':
                    for(auto x: left) for(auto y: right) vals.push_back(x * y);
                    break;
            }
        }
        
        return vals;
    }
};