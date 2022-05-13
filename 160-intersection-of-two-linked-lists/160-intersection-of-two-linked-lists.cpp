/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //calculate length of first ll,second ll
        int n1=0,n2=0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA){
            n1++;
            tempA = tempA->next;
        }
        
        while(tempB){
            n2++;
            tempB = tempB->next;
        }
        
        int diff = abs(n1-n2);
        tempA = headA;
        tempB = headB;
        
        if(n1>n2){
            while(diff--){
                tempA = tempA->next;
            }
        }
        else{
            while(diff--){
                tempB = tempB->next;
            }
        }
        while(tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
        
        
        // Most efficient iterative approach, Time complexity - O(m+n), Space complexity - O(1)
//         ListNode* a = headA;
//         ListNode* b = headB;
//        while(a!=b){
//            a=a ? a->next : headB;
//            b=b ? b->next : headA;
         
//        }
//         return a;
    }
};