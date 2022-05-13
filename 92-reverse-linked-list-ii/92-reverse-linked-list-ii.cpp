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
    void reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex;
        while(curr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head = prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next){
            return head;
        }
        ListNode* l = head;
        ListNode* r = head;
        ListNode* ll = NULL;
        while(left>1){
            ll = l;
            l = l->next;
            left--;
        }
        while(right>1){
            r = r->next;
            right--;
        }
        ListNode* temp = r->next;
        r->next = NULL;
        if(ll){
         ll->next = NULL;   
        }
        reverse(l);
        if(ll){
            ll->next = l;
        }
        ListNode* t = l;
        while(t->next){
            t = t->next;
        }
        t->next = temp;
        if(ll){
            return head;
        }
        else{
            return l;
        }
        
    }
};