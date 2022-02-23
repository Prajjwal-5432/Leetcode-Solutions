//Link: https://leetcode.com/problems/next-greater-node-in-linked-list/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<pair<ListNode*, int>> v;
        vector<int> ans;
        
        for(int i = 0; head != nullptr; ++i, head = head->next) {
            while(!v.empty() and head->val > v.back().first->val) {
                ans[v.back().second] = head->val;
                v.pop_back();
            }
            ans.push_back(0);
            v.push_back({head, i});
        }
        
        return ans;
    }
};