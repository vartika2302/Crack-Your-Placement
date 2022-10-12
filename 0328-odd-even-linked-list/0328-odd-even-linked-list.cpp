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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* o = odd,*e = even;
        ListNode* preo = NULL;
        while(o && e) {
            o->next = e->next;
            preo = o;
            o = o->next;
            if(e) {
                e->next = o ? o->next : NULL;
                e = e->next;
            }
        }
        if(o) 
            o->next = NULL;
        else if(e) {
            e->next = NULL;
        }
        
        ListNode* temp = odd;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = even;
        return odd;
        
        
        
    }
};