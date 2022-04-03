//Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
//Take care of line 22 we are decreasing h

class Solution {
public:
    unordered_map<int, int> postIndex;
    vector<int> preorder;
    
    TreeNode* constructFromPrePostUtil(int *ind, int l, int h, int n) {
        if(*ind >= n or l > h)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[*ind]);
        ++*ind;
        
        if(l == h) 
            return root;
        
        int i = postIndex[preorder[*ind]];
        
        if(i <= h) {
            root->left = constructFromPrePostUtil(ind, l, i, n);
            root->right = constructFromPrePostUtil(ind, i + 1, h - 1, n);
        }
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
    
        this->preorder = preorder;
            
        for(int i = 0; i < n; ++i) 
            postIndex[postorder[i]] = i;
        
        int ind = 0;
        
        return constructFromPrePostUtil(&ind, 0, n - 1, n); 
    }
};