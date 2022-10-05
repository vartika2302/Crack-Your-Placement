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
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>largestVals;
        if(!root) return largestVals;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int maxValAtLevel = INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                maxValAtLevel = max(maxValAtLevel,curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            largestVals.push_back(maxValAtLevel);
        }
        return largestVals;
    }
};