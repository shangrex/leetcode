class TrieNode{
    public:
        TrieNode* nodes[26];
        bool is_end;
        TrieNode(){
            this->is_end = false;
            for(int i = 0; i < 26; i++){
                nodes[i] = NULL;
            }
        }
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            // create trie node
            if(cur->nodes[c-'a'] == NULL){
                cur->nodes[c-'a'] = new TrieNode();
            }
            cur = cur->nodes[c-'a'];
        }
        cur->is_end = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            if(cur->nodes[c-'a'] == NULL)return false;
            else {
                cur = cur->nodes[c-'a'];
            }
        }
        return cur->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(int i = 0; i < prefix.length(); i++){
            char c = prefix[i];
            if(cur->nodes[c-'a'] == NULL)return false;
            cur = cur->nodes[c-'a'];
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