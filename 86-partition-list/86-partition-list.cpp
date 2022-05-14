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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        ListNode* lessList = new ListNode();
        ListNode* moreList = new ListNode();
        ListNode* t1 = lessList,* t2 = moreList, *temp = head;
        while(temp){
            if(temp->val < x){
                t1->next = temp;
                t1 = t1->next;
            }else{
                t2->next = temp;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        lessList = lessList->next;
        moreList = moreList->next;
        if(!lessList){
            return moreList;
        }else if(!moreList){
            return lessList;
        }
        t1->next = moreList;
        return lessList;
    }
};