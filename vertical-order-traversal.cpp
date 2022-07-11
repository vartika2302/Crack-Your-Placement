// We will solve this using level order traversal but we can use inorder, preorder or postorder also.
// Vertical order traversal will be printed in increasing order of verticals and each vertical will be printed in increasing order of levels.
// In case of overlapping nodes, nodes are printed in increasing order (less value nodes will be printed first).
// queue<node,vertical,level>
// map<int,map<int,multiset<int>>>  --->  map<vertical,map<level,multiset<nodes>>>
// multiset is taken as there can be nodes with same value.

// Time complexity - O(NlogN) --> logN due to the multiset or priority queue
// Space complexity - O(N)+O(N)+O(N) --> third O(N) due to some variables we have taken

vector<vector<int>> verticalOrderTraversal(TreeNode* root){
  queue<pair<TreeNode*,pair<int,int>>>q;
  map<int,map<int,multiset<int>>> nodes;
  q.push({root,{0,0}});
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    TreeNode* node = p.first;
    int vertical = p.second.first;
    int level = p.second.second;
    nodes[vertical][level].insert(node->val);
    if(node->left)
      q.push({node->left,{vertical-1,level+1}});
    if(node->right)
      q.push({node->right,{vertical+1,level+1}});
  }
  
  vector<vector<int>>ans;
  for(auto p:nodes){
    vector<int>col;
    for(auto q: p.second){
      col.insert(col.end(),q.second.begin(),q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}

