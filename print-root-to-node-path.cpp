// We can use any of the recursive traversals here (inorder, preorder, postorder). But we will use inorder traversal here as the implementation and explanation of
// inorder traversal is more easy.

// Firstly process root if it's not null and put it into data structure after making sure that the root node is not equal to the given node. 

// Then firstly go to left and return, then go to right and return.

// At the moment, we encounter null just return false.

// If a false is returned it means we don't have the required node in that path.(if left and right both returned false) So just return and remove the last element 
// from the data structure or the element from which we have returned.

// And whenever we encounter the given node, just return the true without removing any element from the data structure(array).

// Time complexity - O(N)
// Space complexity - O(H) auxilliary stack space in recursion

bool getPath(TreeNode* root, vector<int> &res,int node){
  if(!root)
    return false;
  res.push_back(root->val);
  if(root->val==node)
    return true;
  if(getPath(root->left,res,node) || getPath(root->right,res,node))
    return true;
  res.pop_back();
  return false;
}

vector<int> rootToNodePath(TreeNode* root,int node){
  vector<int>res;
  if(root==NULL)
    return res;
  getPath(root,res,node);
  return res;
}
  

