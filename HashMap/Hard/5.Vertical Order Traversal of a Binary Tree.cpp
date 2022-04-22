//Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    map<int, vector<pair<int, int>>> mp;
    void traverse(TreeNode* root, int x, int y) {
        if(root == nullptr) return;
        
        mp[y].push_back({x, root->val});
        traverse(root->left, x + 1, y - 1);
        traverse(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        
        vector<vector<int>> v;
        for(auto [x, y]: mp) {
            sort(y.begin(), y.end(), [&](auto i, auto j) {
                return i.first != j.first ? i.first < j.first : i.second < j.second;   
            });
            
            v.push_back({});
            for(auto i: y) v.back().push_back(i.second);
        }
        
        return v;
    }
};