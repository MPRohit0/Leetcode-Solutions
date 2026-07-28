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
    using ll = ListNode;

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ll *head = new ll(0); // dummy node
        ll *curr = head;

        while(list1 && list2){
            
            if(list1->val < list2->val){
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            }else{
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }

        if(list1) curr->next = list1;
        else if(list2) curr->next = list2;

        ll* temp = head;
        head = head -> next;
        delete temp;

        return head;


    }
};