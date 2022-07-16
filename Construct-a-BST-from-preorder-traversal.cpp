// Brute-force approach - by manually creating BST
// Time complexity - O(n*n) traversing through all nodes and finding the right place to insert a node(travelling height of tree) . Worst case height will be O(N).
// Space complexity - The space for tree which will be returned and that is not counted. No extra space is used.



// Better approach 
// Time complexity - O(NlogN)+O(N)
// Space complexity - O(N)
// Sort the preorder traversal so that inorder traversal will be obtained. Store it in some container.
// Now construct BT which will be BST from the given preorder and inorder traversal.



// Best - by considering upper bound
// Time complexity - O(3*N) - At max each node will be visited at max 3 times.
// Space complexity - O(1) - Ignoring recursion stack space.

TreeNode* bstFromPreorder(vector<int>&res){
  int i=0;
  return build(res,i,INT_MAX);
}

TreeNode* build(vector<int>&res,int &i,int bound){
  if(i==res.size() || res[i]>bound) return NULL;
  TreeNode* root = new TreeNode(res[i++]);
  root->left = build(res,i,root->val);
  root->right = build(res,i,bound);
  return root;
}
