//Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//Even question is about preorder traversal we do postorder traversal

class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};