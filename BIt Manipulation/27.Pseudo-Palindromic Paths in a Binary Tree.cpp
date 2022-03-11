// Link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

class Solution {
public:
    int cnt = 0;
    long num = 0;
    
    void util(TreeNode* root) {
        if(root == nullptr) return;
        
        num ^= (1 << root->val);
        if(root->left == nullptr and root->right == nullptr) cnt += __builtin_popcount(num) < 2;
        
        util(root->left);
        util(root->right);
        num ^= (1 << root->val);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        util(root);
        return cnt;
    }
};