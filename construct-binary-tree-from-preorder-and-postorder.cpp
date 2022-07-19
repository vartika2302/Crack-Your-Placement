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
    
    TreeNode* buildTreeHelper(vector<int>preorder,int preStart,int preEnd,vector<int>postorder,int postStart,int postEnd,map<int,int>&mpp){
        if(preStart>preEnd || postStart>postEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart+1 <= preEnd){
            int idx = mpp[preorder[preStart+1]]-postStart;
            root->left = buildTreeHelper(preorder,preStart+1,preStart+idx+1,postorder,postStart,postStart+idx,mpp);
            root->right = buildTreeHelper(preorder,preStart+idx+2,preEnd,postorder,postStart+idx+1,postEnd-1,mpp);
        }
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>mpp;
        for(int i=0;i<postorder.size();i++){
            mpp[postorder[i]]=i;
        }
        TreeNode* root = buildTreeHelper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;
    }
};
