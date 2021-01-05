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

/*  Solution 1 - Using PQ
    auto comp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);     

    while(l1) {
        pq.push(l1);
        l1 = l1->next;
    }

    while(l2) {
        pq.push(l2);
        l2 = l2->next;
    }

    ListNode *newHead = new ListNode(0);
    ListNode *tail = newHead;

    while(!pq.empty()) {
        tail->next = new ListNode(pq.top()->val);
        // cout << pq.top()->val << endl;
        pq.pop();
        tail = tail->next;
    }

    tail->next = NULL;

    return newHead->next; 
*/

class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1 and !l2) {
            return NULL;
        }
        
        if(!l1) {
            return l2;
        }
        
        if(!l2) {
            return l1;
        }
        
        ListNode *newHead = new ListNode(0);
        ListNode *tail = newHead;
        
        while(l1 and l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if(l1) {
            tail->next = l1;
        }
        
        if(l2) {
            tail->next = l2;
        }
        
        return newHead->next;
    }
};