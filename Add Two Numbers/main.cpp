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
    
    /*
        int n1 = 0, n2 = 0;
        
        ListNode *l1Copy = l1, *l2Copy = l2;
        
        while(l1Copy) {
            l1Copy = l1Copy->next;
            n1++;
        }
        
        while(l2Copy) {
            l2Copy = l2Copy->next;
            n2++;
        }
        
        l1Copy = l1;
        l2Copy = l2;
        
        if(n2 > n1) {
            while(l1Copy->next) {
                l1Copy = l1Copy->next;
            }
            
            for(int i = 0; i < (n2 - n1); i++) {
                l1Copy->next = new ListNode(0);
                l1Copy = l1Copy->next;
            }
        }
        else if(n1 > n2) {
            while(l2Copy->next) {
                l2Copy = l2Copy->next;
            }
            
            for(int i = 0; i < (n1 - n2); i++) {
                l2Copy->next = new ListNode(0);
                l2Copy = l2Copy->next;
            }
        }
        
        l1Copy = l1;
        l2Copy = l2;
        
        ListNode *res = new ListNode(0);
        ListNode *tail = res;
        
        int sum = 0, carry = 0;
        
        while(l1Copy && l2Copy) {
            sum = l1Copy->val + l2Copy->val + carry;
            
            tail->next = new ListNode(sum % 10);
            
            carry = sum / 10;
            
            l1Copy = l1Copy->next;
            l2Copy = l2Copy->next;
            
            tail = tail->next;
        }
        
        if(carry != 0) {
            tail->next = new ListNode(carry);
        }
        
        return res->next;
    */
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *tail = res;
        
        ListNode *l1Copy = l1, *l2Copy = l2;
        
        int carry = 0;
        
        while(true) {
            int n1 = l1Copy == NULL ? 0 : l1Copy->val;
            int n2 = l2Copy == NULL ? 0 : l2Copy->val;
            
            int sum = n1 + n2 + carry;
            
            /* tail->next = new ListNode(sum % 10);
            
            carry = sum / 10; */
            
            if(sum > 9) {
                tail->next = new ListNode(sum - 10);
                carry = 1;
            }
            else {
                tail->next = new ListNode(sum);
                carry = 0;
            } 
            
            if(l1Copy) {
                l1Copy = l1Copy->next;
            }
            
            if(l2Copy) {
                l2Copy = l2Copy->next;
            }
            
            tail = tail->next;
            
            if(l1Copy == NULL && l2Copy == NULL) {
                break;
            }
        }
        
        if(carry) {
            tail->next = new ListNode(carry);
        }
        
        return res->next;
    }
};