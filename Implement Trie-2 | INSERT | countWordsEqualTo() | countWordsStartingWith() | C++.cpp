#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int countPrefix=0;
    int countEndsWith=0;
    
    bool containsKey(char ch) {
        return (links[ch-'a']!=NULL);
    }
    
    void putKey(char ch,Node* node) {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch-'a'];
    }
    
    void increasePrefix() {
        countPrefix++;
    }
    
    void decreasePrefix() {
        countPrefix--;
    }
    
    void increaseEnd() {
        countEndsWith++;
    }
    
    void deleteEnd() {
        countEndsWith--;
    } 
    
    int getEnd() {
        return countEndsWith;
    }
    
    int getPrefix() {
        return countPrefix;
    }
};

class Trie{
    private:
    Node* root;
    
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    // TC - O(length of word)
    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->putKey(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    // TC - O(length of word)
    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }else {
                return 0;
            }
        }
        return node->getEnd();
    }

    // TC - O(length of word)
    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }else {
                return 0;
            }
        }
        return node->getPrefix();
    }

    // TC - O(length of word)
    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->decreasePrefix();
            }else {
                return;
            }
        }
        node->deleteEnd();
    }
};
