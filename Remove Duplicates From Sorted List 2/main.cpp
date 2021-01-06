/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = NULL, *curr = NULL, *next = NULL;
        
        if(head == NULL) {
            return head;
        }
        
        if(head->next == NULL) {
            return head;
        }
        
        curr = head;
        next = head->next;
        
        while(next != NULL) {
            
            if(next != NULL and curr->val == next->val) {
                while(next != NULL and curr->val == next->val) {
                    curr = curr->next;
                    next = next->next;    
                    
                }    
                if(prev) {
                    prev->next = next;
                }
                else {
                    // prev = next;
                    head = next;
                }
                if(curr)
                    curr = curr->next;
                if(next)
                    next = next->next;
            }
            else {
                prev = curr;
                if(curr)
                    curr = curr->next;
                if(next)
                    next = next->next;
            }
        }
        
        return head;
    }
};