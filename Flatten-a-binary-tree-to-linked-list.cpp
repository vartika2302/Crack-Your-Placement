// Three approaches

// 1. Recursive solution
// Time complexity - O(N)
// Space complexity - O(N) , taking worst case height of binary tree as O(N)

TreeNode* prev = null;
void flatten(TreeNode* &root){
  if(root==NULL)
    return;
  flatten(root->right);
  flatten(root->left);
  root->right = prev;
  root->left = NULL;
  prev = root;
}

// 2. Iterative solution
// Time complexity - O(N)
// Space complexity - O(N)

stack<TreeNode*>st;
st.push(root);
TreeNode* curr;
while(!st.empty()){
  curr = st.top();
  st.pop();
  if(curr->right)
    st.push(curr->right);
  if(curr->left)
    st.push(curr->left);
  if(!st.empty())
    curr->right = st.top();
  curr->left = NULL;
}
return curr;


// 3rd Approach using Morris Traversal
// Time complexity - O(N)
// Space complexity - O(1)

curr = root;
while(curr!=NULL){
  if(curr->left!=NULL){
    prev = curr->left;
    while(prev->right)
      prev = prev->right;
    prev->right = curr->right;
    curr->right = curr->left;
  }
  curr = curr->right;
}
