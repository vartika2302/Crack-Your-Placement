// Brute force approach
// Store inorder and apply two sum
// TC - O(N)+O(N)
// SC - O(N)


// Optimal Approach
// Time complexity - O(N)
// Space complexity - O(H)*2 - O(H)


class BSTIterator {
  stack<TreeNode*>stack;
  bool reverse;
  // reverse--> true--> before
  // reverse--> false--> next
  
  public:
  
  BSTIterator(TreeNode* root, bool isReverse){
    reverse = isReverse;
    pushAll(root);
  }
  
  bool hasNext(){
    return !stack.empty();
  }
  
  int next(){
    TreeNode* tmpNode = stack.top();
    stack.pop();
    if(!reverse){
      pushAll(tmpNode->right);
    }else{
      pushAll(tmpNode->left);
    }
    return tmpNode->val;
  }
  
  private:
  
  void pushAll(TreeNode* root){
    while(root){
      stack.push(root);
      if(reverse==true)
        root=root->right;
      else
        root=root->left;
    }
  }
}


class Solution {
  public:
  bool findTarget(TreeNode* root,int k){
    if(!root)
      return false;
  
    BSTIterator l(root,false);     // next()
    BSTIterator r(root,true);      // before()
    
    int i = l.next();
    int j = r.next();
    while(i<j){
      if(i+j==k)
        return true;
      else if(i+j < k)
        i = l.next();
      else
        j = r.next();
    }
    return false;
  }
}
