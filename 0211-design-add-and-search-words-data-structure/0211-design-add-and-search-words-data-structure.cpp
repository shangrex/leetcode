class Trie {
    public:
        bool is_end;
        map<char, Trie*>next;
        Trie() {
            this->is_end = false;
        }
        
};
class WordDictionary {
public:
    Trie *root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *cur = root;
        for(int i = 0; i < word.length(); i++){
            if(cur->next.count(word[i]) == 0){
                Trie *tmp = new Trie();
                cur->next[word[i]] = tmp;
                cur->next['.'] = tmp;
            }
            cur = cur->next[word[i]];
        }
        cur->is_end = true;
    }
    
    bool search(string word) {
        return helper(root, word, 0);
    }
    
    // when encounter '.', then test different way to go down the trie
    bool helper(Trie* cur, string word, int k){
        if(word.length() == k)return cur->is_end;
        bool check = false;
        if(word[k] == '.'){
            for(auto j : cur->next){
                check = helper(j.second, word, k+1);
                if(check)return true;
            }
            return false;
        }
        else if(cur->next.count(word[k]) != 0){
            cur = cur->next[word[k]];
            return helper(cur, word, k+1);
        }
        else return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */