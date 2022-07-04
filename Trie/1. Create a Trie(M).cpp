//https://www.codingninjas.com/codestudio/problems/implement-trie_631356?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

struct Node{
    Node *links[26] = {NULL};
    bool flag = false;
    
    void insert(string word, int idx){
        if(idx == word.length()){
            flag = true;
        }else{
             int c = word[idx] - 'a';
             if(!links[c]){
                Node* newNode = new Node();
                links[c] = newNode;
             }
             links[c]->insert(word, idx+1); 
        }
    }
    
    bool search(string word, int idx){
        if(idx == word.length()){
            return flag;
        }else{
            int c = word[idx] - 'a';
            if(!links[c]) return false;
            return links[c]->search(word, idx+1);
        }
    }
    
    bool startsWith(string word, int idx){
        if(idx == word.length()) return true;
        int c = word[idx] - 'a';
        if(!links[c]) return false;
        return links[c]->startsWith(word, idx+1);
    }
};

class Trie {

private:  Node* root;
    
public:

    /** Initialize your bool isEndOfWord;*/
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
       root->insert(word, 0);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return root->search(word, 0);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return root->startsWith(prefix, 0);
    }
};