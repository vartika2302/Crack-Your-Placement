// We can solve this problem using any of the traversals.
// Time complexity - O(N)
// Space complexity - O(N)

// Serialize: Encodes binary tree into a single string

string serialize(TreeNode* root){
  if(!root)
    return "";
  string s = "";
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty()){
    TreeNode* currnode = q.front();
    q.pop();
    if(currnode == NULL)
      s.append("#,");
    else
      s.append(to_string(currnode->val)+',');
    if(currnode){
      q.push(currnode->left);
      q.push(currnode->right);
    }
  }
  return s;
}


// Deserialize: Decodes the encoded code(string) into the same binary tree
// stringstream: Allows string to be iterated over as objects
// last parameter to getline() is 'delimeter'.

TreeNode deserialize(string data){
  if(data.size()==0)
    return NULL;
  stringstream s(data);
  string str;
  getline(s,str,',');
  TreeNode* root = new TreeNode(stoi(str));
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty()){
    TreeNode* node = q.front();
    q.pop();
    
    getline(s,str,',');
    if(str=='#'){
      root->left = NULL;
    }else{
      TreeNode* leftNode = new TreeNode(stoi(str));
      root->left = leftNode;
      q.push(leftNode);
    }  
    
    getline(s,str,',');
    if(str=='#')
      root->right = NULL;
    else{
      TreeNode* rightNode = new TreeNode(stoi(str));
      root->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}
