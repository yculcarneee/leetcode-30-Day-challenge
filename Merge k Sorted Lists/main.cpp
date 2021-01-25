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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto comp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);    
        
        for(auto list : lists) {
            while(list) {
                pq.push(list);
                list = list->next;
            }
        }
        
        ListNode *head = new ListNode();
        ListNode *tail = head;
        
        while(!pq.empty()) {
            tail->next = new ListNode(pq.top()->val);
            pq.pop();
            tail = tail->next;
        }
        
        return head->next;
    }
};