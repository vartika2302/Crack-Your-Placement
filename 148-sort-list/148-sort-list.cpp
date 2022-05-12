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
    
    //Function to find mid point of linked list
    ListNode* midPoint(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    //Function to merge two sorted list
    ListNode* merge(ListNode* a, ListNode* b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        ListNode*c=NULL;
        if(a->val < b->val){
            c=a;
            c->next = merge(a->next,b);
        }
        else{
            c=b;
            c->next = merge(a, b->next);
        }
        return c;
    }
    
    //Function to sort linked list in ascending order
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* mid=midPoint(head);
        ListNode*fList = head;
        ListNode*sList = mid->next;
        mid->next = NULL;
        
        fList = sortList(fList);
        sList = sortList(sList);
        head = merge(fList,sList);
        return head;
    }
};