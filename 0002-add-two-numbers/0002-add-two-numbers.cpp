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

using ll = ListNode;

class Solution {
public:
    ll* addTwoNumbers(ll* l1, ll* l2) {

        ll* l1_rev = l1;
        ll* l2_rev = l2;

        // ll *l1_save = l1, *l2_save = l2;

        //adding
        ll* ans = new ll(1);
        ll* curr = ans;
        int carry = 0;
        while(l1_rev || l2_rev || carry ){
            if(l1_rev){
                carry += l1_rev->val;
                l1_rev = l1_rev->next;
            }
            if(l2_rev){
                carry += l2_rev->val;
                l2_rev = l2_rev->next;
            }
            cout<<carry<<endl;

            int val = carry % 10;
            carry /= 10;

            curr->next = new ll(val); 
            curr = curr->next;
        }

        //removing dummy
        ll* temp = ans;
        ans = ans -> next;
        delete temp;

        return ans;
    }
};