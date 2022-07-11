// The first node that comes in the vertical order traversal of every vertical line constitutes the top view of binary tree.
// Recursive way will be difficult to implement as we will also have to use the concept of height (as there is the possibility of longest/deepest height node to be
// visited first)
// We are using here level order traversal
// queue<pair<TreeNode*,int>>q  --->  queue<node,vertical>q
// map<int,int>m  --->  map<verticalLine,nodeVal>m

// Time complexity - O(N)
// Space complexity - O(N)

vector<int> topViewOfBinaryTree(TreeNode* root){
  vector<int>res;
  if(root==NULL)
    return res;
  queue<pair<TreeNode*,int>>q;
  map<int,int>m;
  q.push({root,0});
  while(!q.empty()){
    auto curr=q.front();
    q.pop();
    TreeNode* node = curr.first;
    int verticalLine = curr.second;
    if(map.find(verticalLine)==map.end())
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
