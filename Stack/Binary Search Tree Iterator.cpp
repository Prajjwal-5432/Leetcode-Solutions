//Link: https://leetcode.com/problems/binary-search-tree-iterator/
class BSTIterator {
public:
    vector<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    int next() {
        TreeNode* temp = st.back();
        st.pop_back();
        traverse(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void traverse(TreeNode* root) {
        for(; root != nullptr; root = root->left) st.push_back(root);
    }
};