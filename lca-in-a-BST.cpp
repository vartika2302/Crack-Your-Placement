// From the bottom, the first intersection point or from the top, the last intersection point is known as LCA (Lowest Common Ancestor).

// Time complexity - O(log2N) - O(H)
// Space complexity - O(1) or stack space if implemented using recursion

TreeNode* lcaInBST(TreeNode* root, TreeNode* p, TreeNode* q){
  if(root==NULL)
    return NULL;
  int curr = root->val;
  if(curr < p->val && curr < q->val){
    return lcaInBST(root->right,p,q);
  }
  if(curr > p->val && curr > p->val){
    return lcaInBST(root->left,p,q);
  }
  return root;
}
