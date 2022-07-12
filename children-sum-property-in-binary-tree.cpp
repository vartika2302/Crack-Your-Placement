// while going down make the nodes greater, so that there will never be the shortage of value when coming up from bottom to top

// Time complexity - O(N)
// Space complexity - O(H), worst case - O(N)

// Backtracking will be at last
// 1. Top to bottom
// 2. Bottom to top

// Node's value = (left child's value + right child's value)

void convertToChildrenSumProperty(TreeNode* &root){
  if(root==NULL)
    return;
  int child=0;
  if(root->left)
    child += root->left->val;
  if(root->right)
    child += root->right->val;
  if(child >= root->val)
    root->val = child;
  else{
    if(root->left)
      root->left->val = root->val;
    else if(root->right)
      root->right->val = root->val;
  }
  
  convertToChildrenSumProperty(root->left);
  convertToChildrenSumProperty(root->right);
  
  // BACKTRACKING LOGIC
  
  int top = 0;
  if(root->left)
    top += root->left->val;
  if(root->right)
    top += root->right->val;
  if(root->left || root->right)
    root->val = top;
}
