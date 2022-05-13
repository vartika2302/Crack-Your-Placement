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
    void iterativeReverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex;
        while(curr){
            //save the next node
            nex = curr->next;
            //make curr point to prev node
            curr->next = prev;
            //update prev and curr pointers
            prev = curr;
            curr = nex;
        }
        head = prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        iterativeReverse(l1);
        iterativeReverse(l2);
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int sum=0,carry=0;
        ListNode* new_head = new ListNode();
        ListNode* temp = new_head;
        
        while(t1 || t2){
            sum += t1 ? t1->val : 0;
            sum += t2 ? t2->val : 0;
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new ListNode(sum);
            sum = 0;
            temp = temp->next;
            t1 = t1 ? t1->next : NULL;
            t2 = t2 ? t2->next : NULL;
        }
        if(carry){
            temp->next = new ListNode(carry);
            temp = temp->next;
        }
        temp->next = NULL;
        new_head = new_head->next;
        iterativeReverse(new_head);
        return new_head;
    }
};