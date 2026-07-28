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

        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(auto i: lists){
            if(!i) continue;
            pq.push(i);
        } 

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            //pointers
            temp->next = curr;
            temp = temp->next;

            if(temp ->next){
                pq.push(temp ->next);
            }
        }

        return dummy->next;
        
    }
};