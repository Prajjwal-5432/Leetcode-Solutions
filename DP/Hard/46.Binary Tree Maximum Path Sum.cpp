//Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    long ans;
    pair<long, long> dfs(TreeNode* root) {
        if(root == nullptr) return {0, 0};
        pair<long, long> lef = dfs(root->left);
        pair<long, long> rig = dfs(root->right);
        long lmx = max(lef.first, lef.second);
        long rmx = max(rig.first, rig.second);
        
        ans = max(ans, root->val + lmx + rmx);
        ans = max(ans, root->val + lmx);
        ans = max(ans, root->val + rmx);
        ans = max(ans, 1L * root->val);
        
        pair<long, long> res = {root->val + max(lmx, 0L),
                                root->val + max(rmx, 0L)};
                  
        return res;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        
        pair<long, long> res = dfs(root);
        
        return ans;
    }
};