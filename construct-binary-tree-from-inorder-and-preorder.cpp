// Multiple binary trees can be formed from preorder and postorder traversals. But unique binary tree can't be formed.
// A unique binary tree can be formed when the inorder traversal is also given because only root is not required for building the tree. The nodes present in the left
// side of tree and the nodes present in the right side of tree are also required.

// Time complexity - O(N) or O(NlogN) if insertion operation in hashmap takes O(logN) time.
// Space complexity - O(N)


TreeNode* buildTreeHelp(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd, map<int,int>mpp){
  if(preStart>preEnd || inStart>inEnd)
    return NULL;
  TreeNode* root = new TreeNode(preorder[preStart]);
  
  int inRoot = mpp[root->val];
  int numsLeft = inRoot - inStart;
  
  root->left = buildTreeHelp(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mpp);
  root->right = buildTreeHelp(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, mpp);
  return root;
}


TreeNode* buildBinaryTree(vector<int> &inorder, vector<int> &preorder){
  map<int,int>mpp;
  for(int i=0;i<inorder.size();i++){
    mpp[inorder[i]] = i;
  }
  TreeNode* root = buildTreeHelp(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
  return root;
}
