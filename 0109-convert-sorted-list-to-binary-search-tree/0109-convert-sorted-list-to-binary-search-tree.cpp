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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* sortedListToTree(vector<int>& tempStore, int low, int high) {
        if(low>high) return NULL;
        int mid=(low+high)/2;
        TreeNode* root = new TreeNode(tempStore[mid]);
        root->left = sortedListToTree(tempStore, low, mid-1);
        root->right = sortedListToTree(tempStore, mid+1, high);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>tempStore;
        ListNode* node = head;
        int n=0;
        while(node) {
            tempStore.push_back(node->val);
            node = node->next;
            n++;
        }
        
        return sortedListToTree(tempStore,0,n-1);
        
    }
};