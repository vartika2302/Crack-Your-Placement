// Time complexity - O(N) or O(NlogN) if hashmap time complexity is considered as O(logN)
// Space complexity - O(N) for hash map + O(N) for auxilliary stack space.

TreeNode* buildTreeHelp(TreeNode* postorder, int postStart, int postEnd, TreeNode* inorder, int inStart, int inEnd, map<int,int>&mpp){
  if(postStart>postEnd || inStart>inEnd)
    return NULL;
  TreeNode* root = new TreeNode(postorder[postEnd]);
  int inRoot = mpp[root->val];
  int leftNums = inRoot-inStart;
  root->left = buildTreeHelp(postorder, postStart, postStart+leftNums-1, inorder, inStart, inRoot-1, mpp);
  root->right = buildTreeHelp(postorder, postStart+leftNums, postEnd-1, inorder, inRoot+1, inEnd, mpp);
  return root;
}

TreeNode* buildBinaryTree(vector<int> &postorder, vector<int> &inorder){
  if(postorder.size()!=inorder.size())
    return NULL;
  map<int,int>mpp;
  for(int i=0;i<inorder.size();i++){
    mpp[inorder[i]] = i;
  }
  TreeNode* root = buildTreeHelp(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mpp);
  return root;
}
