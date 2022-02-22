//Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/
class CustomStack {
public:
    vector<pair<int, int>> st;
    int index = 0;
    CustomStack(int maxSize) {
        st.resize(maxSize, {0, 0});
    }
    
    void push(int x) {
        if(index == st.size()) return;
        st[index] = {x, 0};
        index++;
    }
    
    int pop() {
        if(index == 0) return -1;
        pair<int, int> val = st[index - 1];
        if(index > 1) st[index - 2].second += val.second;
        st[index - 1] = {0, 0};
        index--;
        return val.first + val.second;
    }
    
    void increment(int k, int val) {
        if(index == 0) return;
        k = min(k, index);
        st[k - 1].second += val;
    }
};
