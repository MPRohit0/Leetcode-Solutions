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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0,head);
        head = dummy;
        
        ListNode* s = head, *e = head;
        for(int i = 0; i<n;i++){
            e = e->next;
        }

        while(e->next){
            s = s->next;
            e = e->next;
        }

        ListNode *toDel = s->next;
        s->next = s->next->next;
        delete toDel;  

        return head->next;
    }
};