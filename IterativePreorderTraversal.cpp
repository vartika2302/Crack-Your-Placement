void preorder(TreeNode* root, vector<int>&res){
  stack<TreeNode*>st;
  if(root==NULL)
    return;
  st.push(root);
  while(!st.empty()){
    TreeNode* curr = st.top();
    st.pop();
    if(curr->right)
      st.push(curr->right);
    if(curr->left)
      st.push(curr->left);
    res.push_back(curr->val);
  }
}

vector<int> iterativePreorder(TreeNode* root){
  vector<int>res;
  preorder(root,res);
  return res;
}
