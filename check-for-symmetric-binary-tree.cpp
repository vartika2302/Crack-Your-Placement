// Time complexity - O(N)
// Space complexity - O(N) - in worst case of skewed tree
// Root L R ----- Root R L

bool isSymmetricHelper(TreeNode* left, TreeNode* right){
  if(left==NULL || right==NULL)
    return left==right;
  if(left->val!=right->val)
    return false;
  return isSymmetricHelper(left->left,right->right)&&isSymmetricHelper(left->right,right->left);
}

bool isSymmetric(TreeNode* root){
  if(root==NULL)
    return true;
  return isSymmetricHelper(root->left,root->right);
}
