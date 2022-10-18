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
public:
    int maxDepth(TreeNode* root) {
        
        // RECURSIVE SOLUTION
        
        // if(!root) return 0;
        // int leftHeight = maxDepth(root->left);
        // int rightHeight = maxDepth(root->right);
        // return max(leftHeight,rightHeight)+1;
        
        // ITERATIVE SOLUTION
        if(!root) return 0;
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            cnt++;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return cnt;
        
    }
};