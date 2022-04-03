//Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
//work on this example
//pre: [1, 2, 4, 8, 9, 5, 3, 6, 7]
//post: [8, 9, 4, 5, 2, 6, 7, 3, 1]

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> s;
        s.push_back(new TreeNode(pre[0]));
        
        for(int i = 1, j = 0; i < pre.size(); ++i) {
            TreeNode* root = new TreeNode(pre[i]);
            
            while(s.back()->val == post[j]) {
                s.pop_back(), j++;
            }
            
            if(s.back()->left == nullptr) s.back()->left = root;
            else s.back()->right = root;
            
            s.push_back(root);
        }
        
        return s.front();
    }
};