// Any given can be inserted at multiple places such that the condition of BST is satisfied.

// T.C - O(log2n)

TreeNode* insertInBST(TreeNode* root,int target){
 if(root==NULL)
   return new TreeNode(target);
 TreeNode* curr = root;
  while(true){
    if(curr->val <= target){
      if(curr->right!=NULL){
        curr = curr->right
      }else{
        curr->right = new TreeNode(target);
        break;
      }
    }else{
      if(curr->left != NULL){
        curr = curr->left;
      }else{
        curr->left = new TreeNode(target);
        break;
      }
    }
  }
  return root;
}
