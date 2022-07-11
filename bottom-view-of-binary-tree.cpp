// The last node in each of the vertical line during the vertical order traversal constitutes the bottom view of the binary tree.
// If the nodes are overlapping, we have to insert the rightmost node
// queue<pair<TreeNode*,int>>q  ---->  queue<pair<node,verticalLine>>q
// map<int,int>m ----> map<verticalLine,nodeVal>m
// Time complexity - O(N)
// Space complexity - O(N)


vector<int> bottomViewOfBinaryTree(TreeNode* root){
  vector<int>res;
  if(root==NULL)
    return res;
  queue<pair<TreeNode*,int>>q;
  map<int,int>m;
  q.push({root,0});
  while(!q.empty()){
    auto curr = q.front();
    q.pop();
    TreeNode* node = curr.first;
    int verticalLine = curr.second;
    map[verticalLine] = node->val;
    if(node->left)
      q.push({node->left,verticalLine-1});
    if(node->right)
      q.push({node->right,verticalLine+1});
  }
  for(auto p:m){
    res.push_back(p.second);
  }
  return res;
}
