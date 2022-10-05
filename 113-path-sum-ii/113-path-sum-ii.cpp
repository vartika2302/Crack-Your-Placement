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
    void pathsHelper(TreeNode* root, int targetSum, vector<vector<int>>& paths,vector<int>&temp) {
        if(!root) return;
         temp.push_back(root->val);
        if(targetSum==root->val && !root->left && !root->right) {
            paths.push_back(temp);
        }
        pathsHelper(root->left,targetSum-root->val,paths,temp);
        pathsHelper(root->right,targetSum-root->val,paths,temp);
        temp.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>paths;
        vector<int>temp;
        pathsHelper(root,targetSum,paths,temp);
        return paths;
    }
};