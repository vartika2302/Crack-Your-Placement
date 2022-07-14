// T.C - O(log2n)

int ceilInBST(TreeNode* root, int key){
  int ceil = -1;
  while(root){
    if(root->val==key){
      ceil = root->val;
      return ceil;
    }else if(root->val<key){
      root = root->right;
    }else{
      ceil = root->val;
      root = root->right;
    }
  }
  return ceil;
}
