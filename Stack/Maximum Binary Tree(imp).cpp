//Link: https://leetcode.com/problems/maximum-binary-tree/
//Refer: https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C%2B%2B-O(N)-solution

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> st;
        
        for(int i = 0; i < nums.size(); ++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            
            while(!st.empty() and st.back()->val < nums[i]) {
                cur->left = st.back();
                st.pop_back();
            }
            
            if(!st.empty()) st.back()->right = cur;
            st.push_back(cur);
        }
        
        return st.front();
    }
};