// 1. Find the parent pointers to all the nodes. ---> (1st bfs)
// 2. If the address or pointer of the target node is given, then no issue. But if the value of target node is given find the address of the node by iterating the binary
// tree by using any traversal techniques.

// DFS can't be applied here as there is a kind of level wise movement here.

// Time complexity - O(N)+O(N) - O(N) or O(NlogN) if insertion of hash map is of logN.
// Space complexity - O(N)+O(N) - O(N)

TreeNode* keepTrackOfParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent_track,int target){
  queue<TreeNode*>q;
  q.push(root);
  TreeNode* res;
  while(!q.empty()){
    TreeNode* curr = q.front();
    if(curr->val == target)
      res = curr;
    q.pop();
    if(curr->left){
      q.push(curr->left);
      parent_track[curr->left] = curr;
    }
    if(curr->right){
      q.push(curr->right);
      parent_track[curr->right] = curr;
    }
  }
  return res;
}

int findMaxDistance(TreeNode* target, unordered_map<TreeNode*, TreeNode*>parent_track){
  queue<TreeNode*>q;
  q.push(target);
  unordered_map<TreeNode*,bool>visited;
  visited[target]=true;
  int maxi=0;
  while(!q.empty()){
    int size = q.size();
    int flag = 0;
    for(int i=0;i<size;i++){
      TreeNode* curr = q.front();
      q.pop();
      if(curr->left && !visited[curr->left]){
        flag = 1;
        q.push(curr->left);
        visited[curr->left] = true;
      }
      if(curr->right && !visited[curr->right]){
        flag = 1;
        q.push(curr->right);
        visited[curr->right] = true;
      }
      if(parent_track[curr] && !visited[parent_track[curr]]){
        flag = 1;
        q.push(parent_track[curr]);
        visited[parent_track[curr]] = true;
      }
    }
    if(flag==1){
      maxi++;
    }
  }
  return maxi;
}

int minTimeToBurnBinaryTree(TreeNode* root, int target){
  unordered_map<TreeNode*,TreeNode*>parent_track;
  TreeNode* targetNode = keepTrackOfParents(root,parent_track,target);
  int maxi = findMaxDistance(targetNode,parent_track);
  return maxi;
}
