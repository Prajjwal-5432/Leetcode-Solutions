//https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
struct Node {
    Node* child[2] = {nullptr};
    int cnt;
    Node(): cnt(0) {};
    ~Node() {
        delete child[0];
        delete child[1];
    }
};
class Solution {
public:
    Node* root;
    void insert(int num) {
        Node* temp = root;
        for(int bit = 14; ~bit; --bit) {
            if(temp->child[num >> bit & 1] == nullptr)
                temp->child[num >> bit & 1] = new Node();
            
            temp->child[num >> bit & 1]->cnt += 1;
            temp = temp->child[num >> bit & 1];
        }
    }
    int count(int num, int k) {
        int pairs = 0;
        Node* temp = root;
        for(int bit = 14; bit >= 0 and temp; --bit) {
            int nb = num >> bit & 1;
            int lb = k >> bit & 1;
            
            if(lb == 0) {
                temp = temp->child[nb];
            } else {
                if(temp->child[nb])
                    pairs += temp->child[nb]->cnt;
                temp = temp->child[nb ^ 1];
            }
        }
        return pairs;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        root = new Node();
        int res = 0;
        for(auto x: nums) {
            res += count(x, high + 1) - count(x, low);
            insert(x);
        }
        delete root;
        return res;
    }
};