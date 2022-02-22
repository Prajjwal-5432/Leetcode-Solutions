//Link: https://leetcode.com/problems/design-browser-history/
class BrowserHistory {
public:
    vector<string> v;
    int index = 0;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
    }
    
    void visit(string url) {
        v.erase(v.begin() + index + 1, v.end());
        v.push_back(url);
        index++;
    }
    
    string back(int steps) {
        steps = min(steps, index);
        index -= steps;
        return v[index];
    }
    
    string forward(int steps) {
        int forw = v.size() - index - 1;
        steps = min(steps, forw);
        index += steps;
        return v[index];
    }
};