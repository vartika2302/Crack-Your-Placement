// Time complexity - O(log2n)
// Space complexity - O(1)

TreeNode* findLastRight(TreeNode* root){
  if(root->right==NULL)
    return root;
  return findLastRight(root->right);
}

TreeNode* helper(TreeNode* root){
  if(root->left==NULL)
    return root->right;
  else if(root->right==NULL)
    return root->left;
  TreeNode* rightNode = root->right;
  TreeNode* lastRight = findLastRight(root->left);
  lastRight->right = rightNode;
  return root->left;
}

TreeNode* deleteInBST(TreeNode* root, int key){
  if(root==NULL)
    return NULL;
  if(root->val == key)
    return helper(root);
  TreeNode* keeper = root;
  while(!root){
    if(root->val > key){
      if(root->left!=NULL && root->left->val == key){
        root->left = helper(root->left);
        break;
      }else{
        root = root->left
      }
    }else{
      if(root->right!=NULL && root->right->val == key){
        root->right = helper(root->right);
        break;
      }else{
        root = root->right
      }
    }
  }
  return keeper;
}
