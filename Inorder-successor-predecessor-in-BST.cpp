// Brute force approach
// Store the inorder traversal of BST in any data structure like vector. Then apply either linear search or binary search to find the inorder successor/predecessor.
// Time complexity - O(N)+(logN) - (Inorder traversal+binary search)
// Space complexity - O(N)




// Better approach
// Time complexity - O(N)
// Space complexity - O(1) - Ignoring any stack space or performing morris traversal.
// Do any traversal, whenever we encounter a node whose val is greater than target then return it. 



// Best approach
// Apply Binary Search Tree Logic
// T.C - O(log2n) - O(H)
// S.C - O(1)


// Inorder successor

TreeNode* inorderSuccessor(TreeNode* root, TreeNode*p){
  TreeNode* successor = NULL;
  while(root){
    if(root->val > p->val){
      successor = root;
      root = root->left;
    }else{
      root = root->right;
    }
  }
  return successor;
}


// Inorder predecessor

TreeNode* inorderPredecessor(TreeNode* root, TreeNode*p){
  TreeNode* predecessor = NULL;
  while(root){
    if(root->val < p->val){
      predecessor = root;
      root = root->right;
    }else{
      root = root->left;
    }
  }
  return predecessor;
}
