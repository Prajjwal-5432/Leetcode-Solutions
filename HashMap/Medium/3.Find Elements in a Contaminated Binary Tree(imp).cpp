//Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
//Refer: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/discuss/431229/Python-Special-Way-for-find()-without-HashSet-O(1)-Space-O(logn)-Time

class FindElements {
public:
    unordered_set<int> st;
    
    void build(TreeNode* root, int val) {
        if(root == nullptr) return;
        
        root->val = val;
        st.insert(val);
        
        if(root->left)
            build(root->left, 2 * val + 1);
        if(root->right)
            build(root->right, 2 * val + 2);
    }
    
    FindElements(TreeNode* root) {
        build(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};
