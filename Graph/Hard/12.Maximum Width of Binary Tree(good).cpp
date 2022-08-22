//Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long res = 0;
        
        while(!q.empty()) {
            long long start = q.front().second;
            res = max(res, q.back().second - q.front().second + 1);
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode *cur = q.front().first;
                long long val = q.front().second;
                
                q.pop();
                
                long long index = val - start;
                
                if(cur->left)
                    q.push({cur->left, 2 * index + 1});
                if(cur->right)
                    q.push({cur->right, 2 * index + 2});
            }
        }
        
        return res;
    }
};