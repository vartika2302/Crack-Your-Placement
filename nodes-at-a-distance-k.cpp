// All nodes at a distance 'k' from the given node.
// We will perform bfs(level order traversal) using queue.
// While putting the left and right nodes we will maintain the parents to those into a map data structure. So that we have the knowledge of the parents of each node.
// So that we can go upwards and downwards both.

// If the reference or address of the node is given then no problem.
// If the value of node is given then we can find the reference or address of the node by iterating or traversing the tree using any traversals.

// After this,
// From the target node, we will always try to go radially upwards and downwards from the target node (dfs traversal).


/******* STEPS ********/
// take a dist variable , initialize it with 0. And increase it in every iteration by 1. 
// Stop iterating when (dist==k);
 
/*** ITERATION ***/
// Push target node into queue
// while
// pop node from the queue and make it visited into visited hashmap and push the nodes radially outward at 1 dist(just outward).
// take all the nodes in the queue and perform the same steps.
// Don't visit already visited nodes again.

// The remaining nodes in the queue are the nodes at a distance 'k'.


/***************** MAIN POINTS ********************/

// 1. Firstly make sure that you have the parent pointers of all the nodes
// 2. At each iteration move 1 distance radially outwards (above, left-down, right-down)
// 3. When distance becomes equal to k, stop the iteration. The nodes we have reached are the required nodes.

// In C++, hashmap time complexity is log(N)

// Time complexity - O(N) + O(N) + O(logN) == O(N)
// Space complexity - O(N) + O(N) + O(N) == O(N)

void trackOfParents(TreeNode* root, TreeNode* target, unordered_map<TreeNode*,TreeNode*>&parent_track){
  queue<TreeNode*>q;
  q.push(root);
  // Fisrt bfs to keep track of nodes.
  while(!q.empty()){
    TreeNode* curr = q.front();
    q.pop();
    if(curr->left){
      q.push(curr->left);
      parent_track[curr->left]=curr;
    }
    if(curr->right){
      q.push(curr->right);
      parent_track[curr->right]=curr;
    }
  }
  
}

vector<int> nodesAtDistanceK(TreeNode* root, TreeNode* target, int k){
  unordered_map<TreeNode*,TreeNode*>parent_track;
  
  //1. Keeping track of parent nodes of each node.
  trackOfParents(root,target,parent_track);
  
  unordered_map<TreeNode*,bool>visited;
  queue<TreeNode*>q;
  q.push(target);
  visited[target] = true;
  int curr_level = 0;
  // Second bfs to go to K level from target node and using our hashtable info
  while(!q.empty()){
    int size = q.size();
    if(curr_level++ == k)
      break;
    for(int i=0;i<size;i++){
      TreeNode* current = q.front();
      q.pop():
      if(current->left && !visited[current->left]){
        q.push(current->left);
        visited[current->left]=true;
      }
      if(current->right && !visited[current->right]){
        q.push(current->right);
        visited[current->right]=true;
      }
      if(parent_track[current] && !visited[parent_track[current]]){
        q.push(parent_track[current]);
        visited[parent_track[current]]=true;
      }
    }
  }
  vector<int>res;
  while(!q.empty()){
    TreeNode* curr = q.front();
    q.pop();
    res.push_back(curr->val);
  }
  return res;
}





