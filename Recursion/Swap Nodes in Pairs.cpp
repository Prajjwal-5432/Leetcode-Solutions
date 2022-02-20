//Link: https://leetcode.com/problems/swap-nodes-in-pairs/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return head;
        
        ListNode* first = head;
        ListNode* headptr = head->next;
        ListNode* prev = nullptr;
        
        while(first != nullptr) {
            ListNode* second = first->next;
            
            if(second == nullptr) break;
            
            first->next = second->next;
            second->next = first;
            
            if(prev != nullptr) prev->next = second;
            
            prev = first;
            first = first->next;
        }
        
        return headptr;
    }
};