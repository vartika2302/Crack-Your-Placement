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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res_head = new ListNode();
        ListNode*temp = res_head;
        int sum=0,carry=0;
        while(l1!=NULL || l2!=NULL){
            sum += l1 ? l1->val : 0;
            sum += l2 ? l2->val : 0;
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new ListNode(sum);
            temp=temp->next;
            sum=0;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if(carry){
            temp->next=new ListNode(carry);
            temp=temp->next;
        }
        temp->next=NULL;
        return res_head->next;
    }
};