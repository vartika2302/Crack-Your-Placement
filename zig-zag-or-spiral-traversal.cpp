// Time complexity-O(N)
// Space complexity-O(N)

vector<vector<int>> spiralTraversal(TreeNode* root){
  vector<vector<int>>zigzag;
  if(root==NULL)
    return zigzag;
  queue<TreeNode*>q;
  q.push(root);
  int flag=1;
  while(!q.empty()){
    int n=q.size();
    vector<int>temp(n);
    for(int i=0;i<n;i++){
      root=q.front();
      q.pop();
      if(root->left)
        q.push(root->left);
      if(root->right)
        q.push(root->right);
      if(flag==1)
        temp[i]=root->val;
      else
        temp[n-i-1]=root->val;
    }
    flag=1-flag;
    zigzag.push(temp);
  }
  return zigzag;
}
