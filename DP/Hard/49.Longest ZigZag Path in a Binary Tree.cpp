//Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root, int dir) {
        if(root == nullptr) return 0;
        int lef = root->left ? 1 + dfs(root->left, 1) : 0;
        int rig = root->right ? 1 + dfs(root->right, 0) : 0;
        ans = max({ans, lef, rig});
        return dir ? rig : lef;
    }
    int longestZigZag(TreeNode* root) {
        int lef = root->left ? 1 + dfs(root->left, 1) : 0;
        int rig = root->right ? 1 + dfs(root->right, 0) : 0;
        ans = max({ans, lef, rig});
        return ans;
    }
};