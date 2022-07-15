// In case of recursion, left recursion tends to happen first, then right recursion.
// T.C - O(N)
// S.C - O(1)

bool isValidBSTHelper(TreeNode* root, int minVal, int maxVal){
  if(root==NULL)
    return true;
  if(root->val >= maxVal || root->val <= minVal)
    return false;
  return isValidBSTHelper(root->left,minVal,root->val) && isValidBSTHelper(root->right, root->val,maxVal);
}

bool isValidBST(TreeNode* root){
  return isValidBSTHelper(root,INT_MIN,INT_MAX);
}


