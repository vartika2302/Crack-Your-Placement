/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int height = 0;
        if(!root)
            return height;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                Node* curr = q.front();
                q.pop();
                for(int i=0;i<curr->children.size();i++) 
                    q.push(curr->children[i]);
            }
            height++;
        }
        return height;
    }
};