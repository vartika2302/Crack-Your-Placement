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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mpp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int vertical = curr.second.first;
            int level = curr.second.second;
            mpp[vertical][level].insert(node->val);
            if(node->left) q.push({node->left,{vertical-1,level+1}});
            if(node->right) q.push({node->right,{vertical+1,level+1}});
        }
        for(auto p: mpp){
            vector<int>temp;
            for(auto r: p.second){
                temp.insert(temp.end(),r.second.begin(),r.second.end());
            }
            res.push_back(temp);
        }
        return res;
        
    }
};