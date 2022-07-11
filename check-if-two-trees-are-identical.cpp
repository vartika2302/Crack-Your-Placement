// Time complexity - O(N)
// Space complexity - O(N)

bool checkIfIdentical(TreeNode* root1, TreeNode* root2){
  if(root1==NULL || root2==NULL)
    return root1==root2;
  return (root1->val==root2->val)&&checkIfIdentical(root1->left,root2->left)&&checkIfIdentical(root1->right,root2->right);
}
