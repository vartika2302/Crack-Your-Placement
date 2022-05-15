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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex = curr->next;
        while(nex){
            if(curr->val != nex->val){
                prev = curr;
                curr = nex;
                nex = nex->next;
            }
            else{
                while(nex && curr->val == nex->val){
                    nex = nex ? nex->next : NULL;
                }
                if(prev){
                    prev->next = nex;
                    curr = nex;
                    nex = nex ? nex->next : NULL;
                }else{
                    curr = nex;
                    nex = nex ? nex->next : NULL;
                    head = curr;
                }
                
            }
        }
        return head;
    }
};