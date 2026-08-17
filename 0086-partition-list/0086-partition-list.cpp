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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0), *left_curr = left;
        ListNode* right = new ListNode(0), *right_curr = right;

        while(head){
            if(head -> val < x){
                left_curr -> next = head;
                left_curr = left_curr -> next;
            }else{
                right_curr -> next = head;
                right_curr = right_curr -> next;
            }

            head = head -> next;
        }
        right_curr -> next = nullptr;

        left_curr->next = right->next;
        return left->next;
    }
};