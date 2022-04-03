//Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> parent, child;
        unordered_map<int, TreeNode*> mp;
        
        for(auto x: descriptions) {
            TreeNode *par = nullptr, *son = nullptr;
            
            if(!mp.count(x[0])) {
                par = new TreeNode(x[0]);
                mp[x[0]] = par;
            } else {
                par = mp[x[0]];
            }
            
            if(!mp.count(x[1])) {
                son = new TreeNode(x[1]);
                mp[x[1]] = son;
            } else {
                son = mp[x[1]];
            }
            
            if(parent.count(x[1])) parent.erase(x[1]);
            
            if(!child.count(x[0])) parent.insert(x[0]);
            
            child.insert(x[1]);
            
            if(x[2]) par->left = son;
            else par->right = son;
        }
        
        return mp[*parent.begin()];
    }
};