// Recursive implementation ---> Preorder traversal
// Time complexity - O(N)
// Space complexity - O(H)

void leftView(TreeNode* root, vector<int>& res, int &level){
  if(root==NULL)
    return;
  if(level==res.size())
    res.push_back(root->val);
  leftView(root->left,res,level+1);
  leftView(root->right,res,level+1);
}

vector<int> leftViewOfBinaryTree(TreeNode* root){
  vector<int>res;
  int level=0;
  leftView(root,res,level);
  return res;
}


// TODO: Iterative (level-order) implementation
