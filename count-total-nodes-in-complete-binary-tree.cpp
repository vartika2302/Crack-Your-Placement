// Brute force

/* Apply any inorder, postorder, preorder, or level order traversals to count the number the nodes in a binary tree */
// Time complexity - O(N)
// Space complexity - O(H). S.C. will not be O(N) in worst case because this complete binary tree with height logN so it can never be skewed tree for which space
// complexity is O(N). // In recursive implementaion, space complexity is due to the recursion call stack.

void countHelp(TreeNode* root, int&cnt){
  if(root==NULL)
    return;
  cnt++;
  countHelp(root->left,cnt);
  countHelp(root->right,cnt);
}

int countNodes(TreeNode* root){
  int cnt=0;
  countHelp(root,cnt);
  return cnt;
}


// Optimal solution
// Time complexity - O(log^2N) or O(logN)^2  -----------> max (logN) nodes will be traversed and time taken to compute the height will be O(logN)
// Space complexity - O(logN) due to recursion callstack

int leftHeight(TreeNode* node){
  int height = 0;
  while(node){
    height++;
    node = node->left;
  }
  return height;
}

int rightHeight(TreeNode* node){
  int height = 0;
  while(node){
    height++;
    node = node->right;
  }
  return height;
}

int countNodesInCompleteBinaryTree(TreeNode* root){
  if(root==NULL)
    return 0;
  int lh = leftHeight(root->left);
  int rh = rightHeight(root->right);
  if(lh==rh)
    return (1<<lh)-1;
  return 1 + countNodesInCompleteBinaryTree(root->left) + countNodesInCompleteBinaryTree(root->right);
}
