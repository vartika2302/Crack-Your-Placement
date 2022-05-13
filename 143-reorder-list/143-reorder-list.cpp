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
    //Function to find the mid point of the linked list
    ListNode* midPoint(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    //Function to iteratively reverse the linked list, O(1) space complexity
    void iterativeReverse(ListNode* &head){
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
    
    void reorderList(ListNode* head) {
        if(!head || !head->next){
           return;
        }
        ListNode* mid = midPoint(head);
        ListNode* secondL = mid->next;
        mid->next = NULL;
        iterativeReverse(secondL);
        ListNode* firstL = head;
        ListNode* newList = new ListNode();
        ListNode* temp = newList;
        while(firstL){
            temp->next = firstL;
            temp=temp->next;
            firstL = firstL->next;
            temp->next = secondL;
            temp=temp->next;
            secondL = secondL ? secondL->next : NULL;
        }
        head = newList->next;
        
    }
};