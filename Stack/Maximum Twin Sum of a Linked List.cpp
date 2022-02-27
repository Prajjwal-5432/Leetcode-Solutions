//Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
//it would be better if we reverse the list from between to get O(1) space soln
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        
        int mx = 0;
        for(int i = 0; i < v.size() and i <= (v.size() / 2) - 1; ++i) {
            mx = max(mx, v[i] + v[v.size() - i - 1]);
        }
        
        return mx;
    }
};