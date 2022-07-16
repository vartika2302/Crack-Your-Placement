// next() - The next node in inorder traversal
// hasnext() - If there is a next node in the inorder traversal, returns true, if not, returns false.
// Brute force
// Stores inorder in a vector , then execute the functions.
// Time complexity - O(1)
// Space complexity - O(N)



// Best approach
// T.C - O(1) on avg - O(N/N)
// S.C - O(H)

private: stack<TreeNode*> st;

public:
BSTIterator(TreeNode* root){
  pushAll(root);
}

// returns if we have a next smallest number
bool hasNext(){
  return !st.empty();
}

// returns the next smallest number
int next(){
  TreeNode* tmpNode = st.top();
  st.pop();
  pushAll(tmpNode->right);
  return tmpNode->val;
}

private:
void pushAll(TreeNode* root){
  while(root){
    st.push(root);
    root = root->left;
  }
}
