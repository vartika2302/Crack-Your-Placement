// Diameter of binary tree is defined as "The longest path between any two nodes."
// The longest path (or diameter) does not need to pass through root
// In any path, each node will come only once.

// Naive approach
// Time complexity - O(N^2)
// Space complexity - auxilliary space - O(N)

int heightOfBinaryTree(TreeNode* root){
  if(root==NULL)
    return 0;
  int lh=heightOfBinaryTree(root->left);
  int rh=heightOfBinaryTree(root->right);
  return max(lh,rh)+1;
}

void diameter(TreeNode*root,int &maxVariable){
  if(root==NULL)
    return;
  int lh=heightOfBinaryTree(root->left);
  int rh=heightOfBinaryTree(root->right);
  maxVariable=max(maxVariable,lh+rh);
  diameter(root->left,maxVariable);
  diameter(root->right,maxVariable);
}

int diameterOfBinaryTree(TreeNode* root){
  int maxi=0;
  diameter(root,maxi);
  return maxi;
}


// Optimal approach
// Time complexity - O(N)

int findDiameter(TreeNode* root, int &diameter){
  if(root==NULL)
    return 0;
  int lh=findDiameter(root->left,diameter);
  int rh=findDiameter(root->right,diameter);
  diameter=max(diameter,lh+rh);
  return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode* root){
  int diameter=0;
  findDiameter(root,diameter);
  return diameter;
}

