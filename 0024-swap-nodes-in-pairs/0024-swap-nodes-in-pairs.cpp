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
    ListNode* swap(ListNode* curr){
        ListNode* second = curr->next;
        curr->next = second->next;
        second->next = curr;
        return second;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head;

        ListNode *prev = nullptr;
        while(curr && curr->next){
            if(curr == head){
                head = curr->next;
            }

            ListNode *next = curr->next->next; 
            ListNode* new_prev = swap(curr);
            if(prev) prev ->next = new_prev;

            prev = curr;
            curr = next ; 
        }

        return head;
    }
};