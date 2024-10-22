class Solution {
public:
    /*
    Approach 1. since only lowercase english letter is possible, so just triverse all the characters for next step
    Use set to check repeated element
    BFS
    
    Approach 2. use '#' to construct next step by using onordered_map
    unordered_map<string, vector<string>> <replaced string, all possible > e.g. <d*g,  {dig, dog}>
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st, words;
        st.insert(beginWord);
        
        for(auto & word: wordList){
            words.insert(word);
        }
        
        int rst = 0;
        queue<string>q;
        q.push(beginWord);
        st.insert(beginWord);
        
        while(!q.empty()){
      
            int level = q.size();
            rst++;
            for(int k = 0; k < level; k++){
                string t = q.front();
                q.pop();
                // cout << t << endl;
                if(t == endWord){
                    return rst;
                }
                for(int i = 0; i < t.length(); i++){
                    string tmp = t;
                    for(char j = 'a'; j <= 'z'; j++){
                        tmp[i] = j;
                        if(st.count(tmp) == 0 && words.count(tmp)){
                            // cout << tmp << endl;
                            q.push(tmp);
                            st.insert(tmp);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};