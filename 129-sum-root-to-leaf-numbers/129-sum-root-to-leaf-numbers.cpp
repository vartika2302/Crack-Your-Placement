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
    void sumHelper(TreeNode* root, int& totalSum, int& tempSum) {
        if(!root) return;
        tempSum = (10*tempSum)+root->val;
        if(!root->left && !root->right) {
            totalSum+=tempSum;
        }
        
        sumHelper(root->left,totalSum,tempSum);
        sumHelper(root->right,totalSum,tempSum);
        tempSum/=10;
    }
public:
    int sumNumbers(TreeNode* root) {
        int totalSum=0;
        int tempSum=0;
        sumHelper(root, totalSum, tempSum);
        return totalSum;
    }
};