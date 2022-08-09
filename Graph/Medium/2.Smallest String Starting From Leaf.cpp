//Link: https://leetcode.com/problems/smallest-string-starting-from-leaf/

class Solution {
public:
    vector<pair<string, TreeNode*>> v;
    void dfs(TreeNode* root, TreeNode* par) {
        if(root == nullptr) return;
        
        TreeNode* nroot = new TreeNode(root->val, par, nullptr);
        dfs(root->left, nroot);
        dfs(root->right, nroot);
        
        if(root->left == nullptr and root->right == nullptr) 
            v.push_back({string(1, char(root->val + 'a')), nroot});
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, nullptr);
        
        sort(v.begin(), v.end());
        while(v.size() > 1 and v.back().first > v.front().first) {
            v.pop_back();
        }
        
        while(v.size() != 1) {
            for(int i = 0; i < v.size(); ++i) {
                TreeNode* temp = v[i].second->left;
                if(temp == nullptr) return v[i].first;
                
                v[i].first.push_back(char(temp->val + 'a'));
                v[i].second = temp;
            }
            
            sort(v.begin(), v.end());
            while(v.size() > 1 and v.back().first > v.front().first) {
                v.pop_back();
            }
        }
        while(v[0].second->left) {
            TreeNode* temp = v[0].second->left;
            v[0].first.push_back(char(temp->val + 'a'));
            v[0].second = temp;
        }
        return v[0].first;
    }
};