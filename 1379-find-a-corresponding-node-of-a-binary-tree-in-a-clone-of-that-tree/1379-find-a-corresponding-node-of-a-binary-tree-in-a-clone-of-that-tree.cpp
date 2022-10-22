/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* node = cloned;
        if(node == NULL)
            return NULL;
        if(node->val == target->val)
            return node;
        TreeNode* l = getTargetCopy(original,cloned->left,target);
        if(l)
            return l;
        return getTargetCopy(original,cloned->right,target);
    }
};