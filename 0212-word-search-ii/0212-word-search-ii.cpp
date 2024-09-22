class TrieNode {
    public:
        bool is_end;
        unordered_map<char, TrieNode*> next;
        string word;
        TrieNode() {
            is_end = false;
            word = "";
        }
};

class Solution {
public:
    /*
    Construct Trie in words to reduce replicate search
    
    */
    
    void dfs(vector<vector<char>> &board, TrieNode* cur, int h, int w, vector<string> &rst){
        int n = board.size(), m = board[0].size();
        if(h >= n || w >= m || h < 0 || w < 0){
            return;
        }
       // cout << h << " " << w  << board[h][w] << endl;            
        
        if(cur->is_end){
            rst.push_back(cur->word);
            cur->is_end = false;
            //return;
        }
        
        char store_char = board[h][w];
        TrieNode *store_cur = cur;
        board[h][w] = '#';
        //cout << board[h][w];
        if(h+1 < n){
            if(cur->next.find(board[h+1][w]) != cur->next.end()){
                store_cur = cur->next[board[h+1][w]];
                dfs(board, store_cur, h+1, w, rst);
            }
        }
        if(w+1 < m){
            if(cur->next.find(board[h][w+1]) != cur->next.end()){
                store_cur = cur->next[board[h][w+1]];
                dfs(board, store_cur, h, w+1, rst);
            }
        }
        if(h-1 >= 0){
            if(cur->next.find(board[h-1][w]) != cur->next.end()){
                store_cur = cur->next[board[h-1][w]];
                dfs(board, store_cur, h-1, w, rst);
            }
        }
        if(w-1 >= 0){
            if(cur->next.find(board[h][w-1]) != cur->next.end()){
                store_cur = cur->next[board[h][w-1]];
                dfs(board, store_cur, h, w-1, rst);
            }
        }
        
        board[h][w] = store_char;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode *root = new TrieNode();
        TrieNode *cur;
        // constrcut trie
        for(auto &word : words){
            cur = root;
            for(int i = 0; i < word.length(); i++){
                if(cur->next.find(word[i]) == cur->next.end()) {
                    cur->next[word[i]] = new TrieNode();
                }
                cur = cur->next[word[i]];
            }
            cur->is_end = true;
            cur->word = word;
        }
        
        vector<string>rst;
        
        cur = root;
        // triverse in the graph using dfs
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(cur->next.find(board[i][j]) != cur->next.end()){
                    //cout << board[i][j] << endl;
                    dfs(board,  cur->next[board[i][j]], i, j, rst);                    
                } 
            }
        }
        
        return rst;
    }
};