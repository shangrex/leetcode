class Trie {
    public:
        bool is_end = false;
        Trie* next[26];
        string word = "";
        Trie(){
            for(int i = 0; i < 26; i++){
                next[i] = NULL;
            }
        }
};

void dfs(vector<vector<char>>&board, Trie* cur, vector<string>& rst, int i, int j){

    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())return;
    if(board[i][j] == '#')return;

    if(cur->next[board[i][j]-'a'] != NULL){
        int node = board[i][j]-'a';
        cur = cur->next[node];
        
        if(cur->is_end){
            rst.push_back(cur->word); 
            cur->is_end = false;    
        }
        
        char tmp = board[i][j];  
        board[i][j] = '#';
        // exist
        dfs(board, cur, rst, i+1, j);
        dfs(board, cur, rst, i-1, j);
        dfs(board, cur, rst, i, j+1);
        dfs(board, cur, rst, i, j-1);
        
        board[i][j] = tmp;
    }
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        // construct Trie
        Trie* root = new Trie();
        for(int i = 0; i < words.size(); i++){
            Trie* cur = root;
            for(int j = 0; j < words[i].length(); j++){
                Trie* tmp = new Trie();
                int node = words[i][j]-'a';
                if(cur->next[node] == NULL) cur->next[node] = tmp;
                cur = cur->next[node];
            }
            cur->is_end = true;
            cur->word = words[i];
        }
        
        vector<string>rst;
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                Trie* cur = root;
                int node = board[i][j]-'a';
                if(cur->next[node] != NULL){
                    // exist
                    dfs(board, cur, rst, i, j);
                }
            }
        }
        
        return rst;
    }
};