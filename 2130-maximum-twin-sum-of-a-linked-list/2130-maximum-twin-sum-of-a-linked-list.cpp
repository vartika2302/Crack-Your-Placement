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
    int pairSum(ListNode* head) {
        int cnt=0;
        vector<int>temp;
        while(head){
            cnt++;
            temp.push_back(head->val);
            head=head->next;
        }
        int maxi=INT_MIN;
        for(int i=0;i<=(cnt/2)-1;i++){
            maxi=max(maxi,temp[i]+temp[cnt-i-1]);
        }
        return maxi;
    }
};