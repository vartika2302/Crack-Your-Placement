// Time complexity - O(N)  - O(N)+O(N) for all nodes traversing, moving to last node of left subtree.
// Space complexity - O(1)
// Morris traversal uses the concept of 'Threaded Binary Tree'.
// In recursive implementation, backtracking takes care of the returning.

// From the last node of the left subtree , we go back to the root node and then go to the right subtree's first node.

// Multiple cases arises

// 1) If (left==NULL)
//    We don't have to connect anything to root. Just print(root) and then move to right

// 2) If (left!=NULL)
//    Before moving to the left make the rightmost node of left subtree point to curr (root) node and then move the curr pointer to left.


// When we come back to the root node how will we determine whether to move left or right. Because at the first instance, we move to left but when the threaded binary 
// tree already exists and we come to the root node, we remove that thread and then move right.

// Inorder Morris Traversal

vector<int> inorderMorris(TreeNode* root){
  vector<int> inorder;
  TreeNode* curr = root;
  while(curr){
    if(curr->left==NULL){
      inorder.push_back(curr->val);
      curr = curr->right;
    }else{
      TreeNode* prev = curr->left;
      while(prev->right && prev->right!=curr){
        prev = prev->right;
      }
      if(prev->right == NULL){
        prev->right = curr;
        curr = curr->left;
      }else{
        prev->right = NULL;
        inorder.push_back(curr->val);
        curr = curr->right;
      }
    }
  }
  return inorder;
}


// Preorder Morris Traversal

vector<int> preorderMorris(TreeNode* root){
  vector<int>preorder;
  TreeNode* curr = root;
  while(curr){
    if(curr->left==NULL){
      preorder.push_back(curr->val);
      curr = curr->right;
    }else{
      TreeNode* prev = curr->left;
      while(prev->right && prev->right!=curr){
        prev = prev->right;
      }
      if(prev->right == NULL){
        prev->right = curr;
        preorder.push_back(curr->val);
        curr = curr->left;
      }else{
        prev->right = NULL;
        curr = curr->right;
      }
    }
  }
  return preorder;
}

