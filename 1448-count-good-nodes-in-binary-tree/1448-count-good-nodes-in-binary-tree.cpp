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
    void preorder(TreeNode* root, int& ans, int maxVal){
        if(!root) return;
        if(root->val >= maxVal){
            ans++;
            maxVal = root->val;
        }
        preorder(root->left,ans,maxVal);
        preorder(root->right,ans,maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans=0;
        preorder(root,ans,INT_MIN);
        return ans;
    }
};