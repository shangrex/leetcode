// class TrieNode {
//     public:
//     bool is_end;
//     TrieNode *nodes[26];
//     TrieNode(){
//         this->is_end = false;
//         for(int i = 0; i < 26; i++){
//             nodes[i] = NULL;
//         }
//     }
// };

// class Trie {
// public:
//     TrieNode *root;
//     Trie() {
//          root = new TrieNode();
//     }
    
//     void insert(string word) {
//         TrieNode *cur = root;
//         for(int i = 0; i < word.length(); i++){
//             if(cur->nodes[word[i] - 'a'] == NULL){
//                 cur->nodes[word[i]-'a'] = new TrieNode();                
//             }
//             cur = cur->nodes[word[i]-'a'];
//         }
//         cur->is_end = true;
//     }
    
//     bool search(string word) {
//         TrieNode*cur = root;
//         for(int i = 0; i < word.length(); i++){
//             if(cur->nodes[word[i]-'a'] == NULL)return false;
//             else {
//                 cur = cur->nodes[word[i]-'a'];
//             }
//         }
//         return cur->is_end;
//     }
    
//     bool startsWith(string prefix) {
//         TrieNode* cur = root;
//         for(int i = 0; i < prefix.length(); i++){
//             if(cur->nodes[prefix[i] -'a'] == NULL)return false;
//             cur = cur->nodes[prefix[i]-'a'];
//         }
//         return true;
//     }
// };

class TrieNode{
    public:
    TrieNode *node[26];
    bool is_end;
    TrieNode(){
        this->is_end = false;
        for(int i = 0; i < 26; i++){
            node[i] = NULL;
        }
    }
};

class Trie {
    public:

    TrieNode *root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            // cout << word[i];
            if(cur->node[word[i]-'a'] == NULL){
                cur->node[word[i]-'a'] = new TrieNode();
            }
            cur = cur->node[word[i]-'a'];
        }
        cur->is_end = true;
    }

    bool search(string word){
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            if(cur->node[word[i] - 'a'] == NULL){
                return false;
            }
            cur = cur->node[word[i]- 'a'];
        }
        return cur->is_end;
    }

    bool startsWith(string prefix){
        TrieNode *cur = root;
        for(int i = 0; i < prefix.length(); i++){
            if(cur->node[prefix[i]-'a'] == NULL){
                return NULL;
            }
            cur = cur->node[prefix[i]-'a'];
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