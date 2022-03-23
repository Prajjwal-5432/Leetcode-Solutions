//Link: https://leetcode.com/problems/shopping-offers/

bool operator<= (const vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size() - 1; ++i) 
        if(a[i] > b[i]) return false;
    return true;
}
int operator* (const vector<int>& a, const vector<int>& b) {
    int res = 0;
    for(int i = 0; i < a.size(); ++i) 
        res += a[i] * b[i];
    return res;
}
void operator+= (vector<int>& a, vector<int>& b) {
    for(int i = 0; i < a.size(); ++i) a[i] += b[i];
}
void operator-= (vector<int>& a, vector<int>& b) {
    for(int i = 0; i < a.size(); ++i) a[i] -= b[i];
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int cost = price * needs;
        
        for(auto x: special) {
            if(x.back() > cost) continue;
            if(x <= needs) {
                needs -= x;
                cost = min(cost, x.back() + shoppingOffers(price, special, needs));
                needs += x;
            }
        }
        
        return cost;
    }
};