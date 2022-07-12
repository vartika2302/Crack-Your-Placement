// width of binary tree is defined as the number of nodes in a particular level between any two nodes which are practically possible.
// maximum width is the maximum number of nodes between any two nodes on a level.

// We will follow level order traversal for solving this problem. Firstly we will index all the nodes hypothetically.
// Then for each level do (lastIndex-firstIndex+1), and select the max.

// Every node in binary tree have at max two sub nodes or children so this '2*i' concept works here.

// INDEXING CONCEPT
/* ----------------- 0-based indexing ----------------- */
// If 0 based indexing is followed, let 'i' is the index of root node then '2*i+1' is the index of left child node and '2*i+2' is the index of right child node.
/* ----------------- 1-based indexing ----------------- */
// If 1 based indexing is followed, let 'i' is the index of root node then '2*i' is the index of left child node and '2*i+1' is the index of right child node.

// We can follow either of the two indexing

// But this indexing will certainly result in overflow condition.
// so take minimal index in each level and subtract that minimal index from all indexes in that level ,then find the corresponding child nodes according to the 
// modified index to avoid overflow.

// i ---> (i-minIndexOfTheParticularLevel) , now find (2*i+1) & (2*i+2)
// Then for each level do (lastIndex-firstIndex+1), and select the max.

// Time complexity - O(N)
// Space complexity - O(N)
// We will do level order traversal

int maxWidthOfBinaryTree(TreeNode* root){
  if(!root)
    return 0;
  int ans=0;
  queue<pair<TreeNode*,int>>q;
  q.push({root,0}):
  while(!q.empty()){
    int n=q.size();
    int first,last;
    int imin = q.front().second;
    for(int i=0;i<n;i++){
      int curr_idx = q.front().second-imin;
      TreeNode* node = q.front().first;
      q.pop();
      if(i==0)
        first=curr_idx;
      if(i==(n-1))
        last=curr_idx;
      if(node->left)
        q.push({node->left,2*curr_idx+1}):
      if(node->right)
        q.push({node->right,2*curr_idx+2});
    }
    ans=max(ans,(last-first+1));
  }
  return ans;
}
