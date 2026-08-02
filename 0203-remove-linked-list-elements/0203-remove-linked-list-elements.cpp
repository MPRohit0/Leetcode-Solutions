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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            if(curr->val == val){
                ListNode* to_del = curr;
                curr = to_del->next;
                if(prev) prev->next = curr;
                else head = curr;
                
                delete to_del;
            }else{
                prev = curr;
                curr = curr ->next;
            }
        }

        return head;
    }
};