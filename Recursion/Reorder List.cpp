//Link: https://leetcode.com/problems/reorder-list/
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp = head;
        
        while(temp) {
            v.push_back(temp);
            temp = temp->next;
        }
        
        int i = 0, j = v.size() - 1;
        vector<ListNode*> ans;
        while(i <= j) {
            ans.push_back(v[i++]);
            ans.push_back(v[j--]);
        }
        
        if(v.size() & 1) ans.pop_back();
        
        for(int i = 0; i < ans.size() - 1; ++i) ans[i]->next = ans[i + 1];
        ans.back()->next = nullptr;
        
        head = ans.front();
    }
};