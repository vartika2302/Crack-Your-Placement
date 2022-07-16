// Correct BST with two nodes swapped

// BRUTE FORCE
// TC - O(2N)+O(NlogN) - storing any traversal, sort it, then again traversing inorder and bst to correct the bst
// SC - O(N) - not considering recursion stack space, only considering the ds to store inorder traversal.



// OPTIMAL APPROACH
// Swap can have two cases - 
//1. Swapped nodes are adjacent in inorder.
//2. Swapped nodes are not adjacent in inorder.

// Violation - prev node's value > curr node's value
// Store first violation and second violation last node
// And swap first violation's first and second violation last

// If there is no second violation
// Swap first violation's first and first violation's last
// TC - O(N)
// SC - O(1)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
private: 
    void inorder(TreeNode* root) {
        if(root == NULL) return; 
        
        inorder(root->left);
        
        if (prev != NULL && (root->val < prev->val))
        {
           
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                last = root;
        }
 
        // Mark this node as previous
        prev = root;
        inorder(root->right); 
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val); 
    }
};
