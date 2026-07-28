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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        
        ListNode* curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }
        if(n==0||n==1) return head;

        k = k%n;

        if(k==0) return head;

        //1 rotation = 2nd from end = n-2 th element is needed.
        curr = head;
        for(int i =0;i<n-k-1;i++){
            curr = curr->next;
        } 

        ListNode* toDel = curr;
        curr = curr->next;
        toDel->next = nullptr; 

        ListNode *temp = curr;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;

        return curr;

    }
};