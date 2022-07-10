/* We can use either recursive or iterative traversal to find the height (or max depth) of binary tree. Both have their own pros and cons. In the worst case they tend to
take the same space complexity.*/

// RECURSIVE TRAVERSAL
/* The worst case is of Skewed tree. Worst case space complexity in case of recursive traversal is O(N) */
// TC - O(H)

// ITERATIVE TRAVERSAL
/* The worst case is of complete binary tree(last level has many number of nodes). Worst case space complexity will be O(N) */

/* In most cases we will use recursive traversal as chances of skewed tree will be very less */

// TC-O(N)
// SC-O(N)
int heightOfBinaryTree(TreeNode* root){
  if(root==NULL){
    return 0;
  }
  int leftHeight = heightOfBinaryTree(root->left);
  int rightHeight = heightOfBinaryTree(root->right);
  return 1+max(leftHeight,rightHeight);
}

// Using Level order traversal

int maxDepthOfBinaryTree(TreeNode* root){
  int ans=0;
  queue<TreeNode*>q;
  if(root==NULL){
    return ans;
  }
  q.push(root);
  TreeNode*curr;
  while(!q.empty()){
    int n=q.size();
    ans++;
    for(int i=0;i<n;i++){
      curr=q.front();
      q.pop();
      if(curr->left)
        q.push(curr->left);
      if(curr->right)
        q.push(curr->right);
    }
    return ans;
  }
}
