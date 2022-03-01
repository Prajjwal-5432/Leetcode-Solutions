//Link: https://leetcode.com/problems/number-of-atoms/

class Solution {
public:
    vector<int> pair;
    string s;
    
    unordered_map<string, int> parse(int l, int r) {
        unordered_map<string, int> ans;
        
        for(int i = l; i < r + 1; ++i) {
            if(isupper(s[i])) {
                string element = string(1, s[i]), digit;
                int ind = i + 1;
                
                while(ind < r + 1 and s[ind] != '(' and !isupper(s[ind])) element += s[ind++];
                while(isdigit(element.back())) digit += element.back(), element.pop_back();
                
                reverse(digit.begin(), digit.end());
                
                if(digit.empty()) digit = "1";
                ans[element] += stoi(digit);     
                
                i = ind - 1;
            } else if(s[i] == '(') {
                unordered_map<string, int> mp = parse(i + 1, pair[i] - 1);
                
                int digit = 0;
                int ind = pair[i] + 1;
                
                while(ind < r + 1 and isdigit(s[ind])) digit = digit * 10 + (s[ind++] - '0');
                if(digit == 0) digit = 1;
                
                for(auto [x, y]: mp) ans[x] += y * digit;
                
                i = ind - 1;
            }
        }
        return ans;
    }
    
    string countOfAtoms(string formula) {
        int n = formula.size();
        this->s = formula;
        
        pair.resize(n);
        
        vector<int> v;
        for(int i = 0; i < n; ++i) {
            if(formula[i] == '(') {
                v.push_back(i);
            } else if(formula[i] == ')') {
                pair[v.back()] = i;
                pair[i] = v.back();
                v.pop_back();
            }
        }
        
        unordered_map<string, int> mp = parse(0, n - 1);
        
        map<string, int> ans(mp.begin(), mp.end());
        
        string t;
        for(auto [x, y]: ans) t += x + (y > 1 ? to_string(y) : "");
        return t;
    }
};