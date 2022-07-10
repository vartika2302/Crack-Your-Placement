// Do iterative preorder, inorder, postorder traversals using 1 stack and 1 traversal

vector<int> preInPost(TreeNode* root){
  stack<pair<TreeNode*,int>>st;
  vector<int>pre,in,post;
  if(root==NULL){
    return;
  }
  st.push({root,1});
  while(!st.empty()){
    TreeNode* node=st.top();
    st.pop();
    
    // For preorder
    // increment 1 to 2
    // push the left side of the tree
    if(node.second==1){
      preorder.push_back(node.first->val);
      node.second++;
      st.push(node);
      if(node.first->left){
        st.push(node.first->left,1);
      }
    }
    
    // For inorder
    // increment 2 to 3
    // push the right side of the tree
    if(node.second==2){
      inorder.push_back(node.first->val);
      node.second++;
      st.push(node);
      if(node.first->right){
        st.push(node.first->right,1);
      } 
    }
    
    // For postorder
    else{
      postorder.push_back(node.first->val);
    }
  }
}
