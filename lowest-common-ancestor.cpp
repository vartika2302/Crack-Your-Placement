// The common ancestors of the two nodes given that is having the deepest height is called lowest common ancestor (LCA).

// Brute force - Find the path from root to the two nodes store them in the seperate data structures or arrays. Then traverse the two arrays(path) simultaneously,
// the last matched element(node) will be the lowest common ancestor (LCA).
// Extra time complexity of - O(2*N)
// Extra space complexity - O(2*N)


// Optimal soln
// Time complexity - O(N)
// Space complexity - O(N) - worst case
TreeNode* lca(TreeNode* root,TreeNode* a,TreeNode* b){
  if(root==NULL || root==a || root==b)
    return root;
  TreeNode* llca=lca(root->left,a,b);
  TreeNode* rlca=lca(root->right,a,b);
  if(llca==NULL)
   return rlca;
  else if(rlca==NULL)
    return llca;
  else
    return root;
}
