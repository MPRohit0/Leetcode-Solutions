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
        ListNode* temp = new ListNode(0);
        ListNode* nhead = temp;

        while(head){
            int curr_val = head -> val;

            if(head->next && head -> next -> val == curr_val){
                while(head && head -> val == curr_val){
                    head = head -> next;
                }
                continue;
            }

            temp -> next = head; 
            temp = temp -> next;
            head = head -> next;
        }
        temp -> next = nullptr;

        return nhead->next;
    }
};