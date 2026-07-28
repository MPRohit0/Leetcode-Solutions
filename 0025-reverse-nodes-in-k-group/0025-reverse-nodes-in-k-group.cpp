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
    ListNode* rev(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;

            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* local_head = head, *prev = nullptr, *curr = head;
        //curr will be on the last node of a set
        for(int i=0;i<k-1;i++) curr = curr->next;

        //mainloop
        while(curr){
            //saving ends
            ListNode* save = curr->next;
            
            //making a set independent
            curr->next = nullptr;
            if(prev) prev->next = nullptr;

            //reversing the set
            ListNode* new_head = rev(local_head);
            //local head will be the tail
            ListNode* tail = local_head;
            if(!prev) head = new_head; //fixing the head;

            //weaving
            if(prev) prev->next = new_head;
            tail->next = save;

            //resetting 
            prev = tail;
            local_head = tail->next;
            curr = local_head;
            for(int i=0;i<k-1;i++){
                if(!curr) return head;
                curr = curr->next;
            }

        }
        return head;
    }
};