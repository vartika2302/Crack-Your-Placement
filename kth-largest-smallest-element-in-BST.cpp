// Naive approach - Do any traversal and store BST into any vector, sort vector, and return the appropriate element
// Time complexity - O(N)+O(Nlog2N)
// Space complexity - O(N)




// Optimal Approach
// Time complexity - O(N)
// Space complexity - O(1)

node* kthlargest(node* root,int& k)
{
	if(root==NULL)
	return NULL;
	
	node* right=kthlargest(root->right,k);
	if(right!=NULL)
	return right;
	k--;
	
	if(k==0)
	return root;
	
	return kthlargest(root->left,k);
}

node* kthsmallest(node* root,int &k)
{
	if(root==NULL)
	return NULL;
	
	node* left=kthsmallest(root->left,k);
	if(left!=NULL)
	return left;
	k--;
	if(k==0)
	return root;
	
	return kthsmallest(root->right,k);
}
