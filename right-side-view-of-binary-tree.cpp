// The last node of each level if the level nodes are stored from left to right or the first node of each level if the level nodes are stored from right to left
// constitutes the right side view of binary tree.

// We can implement this using both recursive (inorder,preorder,postorder) traversals as well as iterative(bfs-->level order).
// Both have their own pros and cons.

// In level order, in the worst case queue will store N/2 nodes (in case of complete binary tree). Time complexity will be O(N)
// In recursive, space complexity will be of O(H). In the worst case(case of skewed tree), space complexity will be O(N). But this case is very rare and have less 
// possibility of occurence. Time complexity - O(N)

// Recursive implementation
// We will use reverse preorder traversal (Root--Right--Left)

void rightSideView(TreeNode* root, vector<int>&res, int&level){
  if(root==NULL)
    return;
  if(level==res.size())
    res.push_back(root->val);
  rightSideView(root->right,res,level+1);
  rightSideView(root->left,res,level+1);
}

vector<int> rightViewOfBinaryTree(TreeNode* root){
  vector<int>res;
  int level=0;
  rightSideView(root,res,level);
  return res;
}



// TODO: Iterative(level-order implementation)
