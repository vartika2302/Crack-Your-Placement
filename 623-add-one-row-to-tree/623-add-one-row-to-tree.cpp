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
    void addHelper(TreeNode* root, int val, int depth, int d) {
        if(!root) return;
        if(d==(depth-1)) {
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            leftNode->left = root->left;
            leftNode->right = NULL;
            rightNode->left = NULL;
            rightNode->right = root->right;
            root->left = leftNode;
            root->right = rightNode;
            return;
        }
        addHelper(root->left,val,depth,d+1);
        addHelper(root->right,val,depth,d+1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return NULL;
        if(depth==1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        addHelper(root, val, depth, 1);
        return root;
    }
};