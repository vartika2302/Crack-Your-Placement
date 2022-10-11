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
    int f(TreeNode* root, map<TreeNode*,int>& dp) {
        if(!root) return 0;
        if(dp[root]) return dp[root];
        int pick = root->val;
        if(root->left) pick+=f(root->left->left,dp)+f(root->left->right,dp);
        if(root->right) pick+=f(root->right->left,dp)+f(root->right->right,dp);
        int not_pick = f(root->left,dp) + f(root->right,dp);
        return dp[root]=max(pick,not_pick);
    }
    
public:
    int rob(TreeNode* root) {
        map<TreeNode*,int>dp;
        return f(root,dp);
        
    }
};