class TrieNode {
    public:
    bool is_end;
    TrieNode *node[26];
    TrieNode(){
        is_end = false;
        for(int i = 0; i < 26; i++){
            node[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
       root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.length(); i++){
            //cout << word[i];
            if(cur->node[word[i]-'a'] == NULL) cur->node[word[i]-'a'] = new TrieNode();
            cur = cur->node[word[i]-'a'];
        }
        cur->is_end = true;
    }
    
    bool helper(string &word, int idx, TrieNode *cur){
        bool flag = false;
        
        if(idx == word.length()) {
            return  cur->is_end;
        }
        
        if(word[idx] != '.'){
            if(cur->node[word[idx]-'a'] == NULL) return false;
            cur = cur->node[word[idx]-'a'];
            return helper(word, idx+1, cur);
        }
        else {
            TrieNode *tmp;
            for(int i = 0; i < 26; i++){
                if(cur->node[i] != NULL) {
                    tmp = cur->node[i];
                    flag |= helper(word, idx+1, tmp);
                }
            }
        }
        
        return flag;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        return helper(word, 0, cur);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */