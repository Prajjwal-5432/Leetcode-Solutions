//Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
class Solution {
public:
    int idx = 0;
    TreeNode* construct(vector<int> preorder, int mi, int mx) {
        if(idx == preorder.size()) return nullptr;
        if(preorder[idx] < mi or preorder[idx] > mx) return nullptr;
            
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        
        node->left = construct(preorder, mi, preorder[idx - 1]);
        node->right = construct(preorder, preorder[idx - 1], mx);
        
        return node;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, INT_MIN, INT_MAX);
    }
};