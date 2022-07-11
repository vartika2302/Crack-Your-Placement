// Maximum path sum in a binary tree
// The maximum sum of the nodes between any two nodes.

// Naive soln
// Time complexity - O(N^2)

int findMaxPathSum(TreeNode* root){
  if(root==NULL)
    return 0;
  int ls=findMaxPathSum(root->left);
  int rs=findMaxPathSum(root->right);
  return root->val+max(ls,rs);
}

int maxPathSum(TreeNode* root){
  if(root==NULL)
    return 0;
  int lsum=findMaxPathSum(root->left);
  int rsum=findMaxPathSum(root->right);
  return root->val+lsum+rsum;
  maxPathSum(root->left);
  maxPathSum(root->right);
}



// Optimal Soln
// Time complexity - O(N)
// Backtracking logic - important
int findMaxPathSum(TreeNode* root, int&maxSum){
  if(root==NULL)
    return 0;
  int ls=max(0,findMaxPathSum(root->left));  // ignoring the -ve sum if coming from left subtree (taking 0 instead of the -ve sum)
  int rs=max(0,findMaxPathSum(root->right)); // ignoring the -ve sum if coming from right subtree (taking 0 instead of the -ve sum)
  maxSum=max(maxSum,root->val+ls+rs);
  return root->val+max(ls,rs);
}

int maxPathSum(TreeNode* root){
  int maxSum=INT_MIN;
  findMaxPathSum(root,maxSum);
  return maxSum;
}
