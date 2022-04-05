//Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Careful (line 16) first we create the right subtree then the left one

class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> postorder;
    
    TreeNode* build(int l, int r, int *index) {
        if(l > r) return nullptr;
        
        int cur = postorder[*index];
        TreeNode* root = new TreeNode(cur);
        (*index)--;
        
        int split = mp[cur];
        root->right = build(split + 1, r, index);
        root->left = build(l, split - 1, index);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        for(int i = 0; i < n; ++i)
            mp[inorder[i]] = i;
        
        this->postorder = postorder;
        
        int index = n - 1;
        return build(0, n - 1, &index);
    }
};