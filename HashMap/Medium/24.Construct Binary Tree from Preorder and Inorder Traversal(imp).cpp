//Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    vector<int> preorder;
    unordered_map<int, int> index;
    
    TreeNode* build(int l, int r, int *i) {
        if(l > r) return nullptr;
        
        int cur = preorder[*i];
        TreeNode* root = new TreeNode(cur);
        
        (*i)++;
        
        if(l == r) return root;
        
        int ind = index[cur];
        root->left = build(l, ind - 1, i);
        root->right = build(ind + 1, r, i);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        
        int n = preorder.size();
        for(int i = 0; i < n; ++i)
            index[inorder[i]] = i;
        
        int i = 0;
        return build(0, n - 1, &i);
    }
};