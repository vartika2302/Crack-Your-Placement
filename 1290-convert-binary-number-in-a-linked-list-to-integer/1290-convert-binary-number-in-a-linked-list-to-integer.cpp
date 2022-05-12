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
    int getDecimalValue(ListNode* head) {
        if(head->next==NULL){
            return head->val;
        }
        
        //reverse the linked list
        //iterative approach
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex;
        while(curr!=NULL){
            // save the next node;
            nex = curr->next;
            // point curr node to prev node
            curr->next = prev;
            //update prev and curr pointers
            prev=curr;
            curr=nex;
        }
        head=prev;
        
        int multiplier = 1;
        int decimal_val=0;
        while(head!=NULL){
            decimal_val += (head->val)*multiplier;
            multiplier = multiplier*2;
            head = head->next;
        }
        return decimal_val;
        
    }
    
    
};