// Iterative postorder traversal using 2 stacks

vector<int> postorderTraversal(TreeNode* root){
  vector<int> postorder;
  if(root==NULL)
    return postorder;
  
  stack<TreeNode*>st1,st2;
  st1.push(root);
  TreeNode* node;
  while(!st1.empty()){
    node=st1.top();
    st1.pop();
    st2.push(node);
    if(node->left)
      st1.push(node->left);
    if(node->right)
      st1.push(node->right);
  }
  while(!st2.empty()){
    postorder.push_back(st2.top()->val);
    st2.pop();
  }
  return postorder;
}
