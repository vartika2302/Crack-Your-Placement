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
    void helperSumLeft(TreeNode* root, int &sum) {
        if(!root)
            return;
        if(root->left && root->left->left==NULL && root->left->right==NULL)
            sum+=root->left->val;
        helperSumLeft(root->left,sum);
        helperSumLeft(root->right,sum);

        }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int sum=0;
        helperSumLeft(root, sum);
        return sum;
    }
};