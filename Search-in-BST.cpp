// Binary-Search Tree (BST)
/* In BST, everything on left of node should be smaller, and everything on right of node should be greater. */
// BST condition - 
// 1.)  left < node < right
// 2.) Left subtree must also be a BST
// 3.) Right subtree must also be a BST
                                         
// In general, duplicates are not allowed in BST, but if we want duplicates, Then condition is slightly changed as - 
//   left <= node < right

// Why BST ?
// In BT, all traversals will take O(N) time. Length will be O(N).
// In BST, except degenerate trees, traversal(search) take O(log2N)(Base 2) almost everytime. Heights will be generally log2N.

// Time complexity - O(log2N)   , O(N) in case of degenerate tree
// Space complexity - O(log2N)  , O(N) in case of degenerate tree

void searchHelper(TreeNode* root, int target, TreeNode* &res){
  if(root==NULL)
    return;
  if(root->val==target)
    res = root;
  else if(root->val < target)
    res = searchHelper(root->right, target, res);
  else
    res = searchHelper(root->left, target, res);
}

TreeNode* searchInBST(TreeNode* root, int target){
  TreeNode* res = NULL;
  searchHelper(root,target,res);
  return res;
}

// Second soln
TreeNode* searchInBST(TreeNode* root,int target){
  while(root!=NULL && root->val!=target){
    root = (target<root->val)?(root->left):(root->right);
  }
  return root;
}
