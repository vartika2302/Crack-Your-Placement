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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = NULL,* curr = head,* nex = head;
        while(n--){
            nex = nex->next;
        }
        while(nex){
            prev = curr;
            curr = curr->next;
            nex = nex->next;
        }
        if(prev == NULL){
            return head->next;
        }
        prev->next = curr->next;
        return head;
    }
};