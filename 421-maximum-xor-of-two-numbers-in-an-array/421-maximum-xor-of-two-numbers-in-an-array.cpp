class Node {
    private:
    Node* links[2];
    
    public:
    bool containsKey(int bit) {
        return (links[bit]!=NULL);
    }
    
    Node* get(int bit) {
        return links[bit];
    }
    
    void put(int bit, Node* node) {
        links[bit]=node;
    }
};

class Trie {
    private:
    Node* root;
    
    public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* node = root;
        for(int i=31;i>=0;i--) {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)) {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int num) {
        Node* node = root;
        int maxNum=0;
        for(int i=31;i>=0;i--) {
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)) {
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor=0;
        Trie* t = new Trie();
        for(int i=0;i<nums.size();i++) {
            t->insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++) {
            maxXor = max(maxXor,t->getMax(nums[i]));
        }
        return maxXor;
    }
};