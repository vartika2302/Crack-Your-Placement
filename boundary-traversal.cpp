// Boundary traversal will be made of three traversals or three steps basically.

// ANTICLOCKWISE BOUNDARY TRAVERSAL

// Initially push the root node as it belongs to both the left and right boundary.
// 1. Left boundary excluding the leaf nodes --> Go to left,left,left... if the left does not exist then go to right.
// 2. Leaf nodes --> Perform any of the preorder, inorder or postorder traversals. It's just we have to take the left leaf node first. Level order traversal can't be used
// here because of the difference in the level of the leaf nodes.
// 3. Right boundary in the reverse order excluding the leaf nodes. --> Go to right,right,right...if the right does not exist then go to left node. Store this in stack.
// Then push all the elements into the data structure containing boundary traversal.

// Time complexity - O(H)+O(H)+O(N)
// Space complexity - O(N) (auxilliary space)

bool isLeaf(TreeNode* root){
  if(root->left==NULL && root->right==NULL)
    return true;
  return false;
}

void leftBoundary(TreeNode* root,vector<int> &res){
  TreeNode* curr = root->left;
  while(curr){
    if(!isLeaf(curr))
      res.push_back(curr->val);
    if(curr->left)
      curr=curr->left;
    else
      curr=curr->right;
  }
}

void rightBoundary(TreeNode* root,vector<int> &res){
  TreeNode* curr = root->right;
  vector<int>temp;
  while(curr){
    if(!isLeaf(curr))
      temp.push_back(curr->val);
    if(curr->right)
      curr=curr->right;
    else
      curr=curr->left;
  }
  for(int i=temp.size()-1;i>=0;i--){
    res.push_back(temp[i]);
  }
}

void addLeaves(TreeNode* root,vector<int> &res){
  if(isLeaf(root)){
    res.push_back(root->val);
    return;
  }
  if(root->left) addLeaves(root->left,res);
  if(root->right) addLeaves(root->right,res);
}

vector<int> boundaryTraversal(TreeNode* root){
  vector<int>res;
  if(!root) return res;
  if(!isLeaf(root)) res.push_back(root->val);
  leftBoundary(root,res);
  addLeaves(root,res);
  rightBoundary(root,res);
  return res;
}
