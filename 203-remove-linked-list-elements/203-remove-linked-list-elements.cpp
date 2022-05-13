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
        if(head==NULL){
            return head;
        }
        ListNode*prev = NULL;
        ListNode*curr = head;
        while(curr){
            if(curr->val == val){
                if(prev==NULL){
                    head=head->next;
                    curr = head;
                }
                else{
                     prev->next = curr->next;
                curr = prev->next;
                }
               
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};