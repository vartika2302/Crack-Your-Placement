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
    
    // Function to find mid point of linked list
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
    
    // Function to reverse the linked list
    void reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex;
        while(curr){
            //save the next node
            nex = curr->next;
            //make curr node point to previous node
            curr->next = prev;
            //update prev and curr pointers
            prev = curr;
            curr = nex;
        }
        head = prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        ListNode* mid = midPoint(head);
        ListNode* t1 = head;
        ListNode* t2 = mid->next;
        mid->next = NULL;
        
        reverse(t2);
       
        while(t1 && t2){
            if(t1->val != t2->val){
                return false;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return true;
    }
};