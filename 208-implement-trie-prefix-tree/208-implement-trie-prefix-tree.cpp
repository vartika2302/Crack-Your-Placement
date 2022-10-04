struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch) {
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setFlag() {
        flag = true;
    }
    
    bool isEnd() {
        return flag;
    }
    
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    // TC: O(length of the word to be inserted)
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            // move to the reference trie
            node = node->get(word[i]);
        }
        node->setFlag();
    }
    
    // TC: O(length of the word to be searched)
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++) {
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        if(node->isEnd()){
            return true;
        }
        return false;
    }
    
    // TC: O(length of prefix)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++) {
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */