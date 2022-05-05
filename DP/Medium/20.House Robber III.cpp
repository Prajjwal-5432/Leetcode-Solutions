//Link: https://leetcode.com/problems/house-robber-iii/

class Solution {
public:
    map<pair<TreeNode*, bool>, long> mp;
    
    long rob(TreeNode* root, int took = 0) {
        if(root == nullptr) return 0;
        if(mp.count({root, took})) return mp[{root, took}];
        
        long ans = 0;
        if(took == 1) {
            ans = max(ans, rob(root->left, 0) + rob(root->right, 0));
        } else {
            ans = max(ans, root->val + rob(root->left, 1) + rob(root->right, 1));
            ans = max(ans, rob(root->left, 0) + rob(root->right, 0));
        }
        
        return mp[{root, took}] = ans;
    }
};