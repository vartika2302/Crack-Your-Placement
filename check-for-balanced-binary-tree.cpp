// Naive approach
// Time complexity - O(N^2)
// Space complexity - O(N)- Auxilliary space

int heightOfBinaryTree(TreeNode* root){
  if(root==NULL)
    return 0;
  int lh=heightOfBinaryTree(root->left);
  int rh=heightOfBinaryTree(root->right);
  return 1+max(lh,rh);
}

bool checkForBalancedTree(TreeNode* root){
  if(root==NULL)
    return true;
  int lh = heightOfBinaryTree(root->left);
  int rh = heightOfBinaryTree(root->right);
  if(abs(lh-rh)>1)
    return false;
  int leftCheck = checkForBalancedTree(root->left);
  int rightCheck = checkForBalancedTree(root->right);
  if(leftCheck==false || rightCheck==false)
    return false;
  return true;
}
 
// Optimal Soln
// Time complexity - O(N)
// Space complexity - O(N)
// dfs height
int check(TreeNode* root){
  if(root==NULL)
    return 0;
  int lh=check(root->left);
  if(lh==-1)
    return -1;
  int rh=check(root->right);
  if(rh==-1)
    return -1;
  if(abs(lh-rh)>1)
    return -1;
  return 1+max(lh,rh);
}

bool checkForBalancedTree(TreeNode* root){
  return check(root)!=-1;
}
