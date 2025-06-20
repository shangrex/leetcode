class myCompare {
    public:
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2){
    // if same count then small lexigo first
    // count big first
    if(p1.first == p2.first){
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
    }
};
class TrieNode{
    public:
    bool isEnd;
    TrieNode *next[26];
    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
};
class Solution {
public:
    /*
    Approach 1.use prioirty_queue with customize operator function
    Approach 2. Trie + bucket
    Approach 3. sort 

    */
    // vector<string> topKFrequent(vector<string>& words, int k) {
    //     map<string, int> mp;
    //     priority_queue<pair<int, string>, vector<pair<int, string>>, myCompare>pq;
        
    //     for(auto &word : words){
    //         mp[word] += 1;
    //     }

    //     for(auto &it : mp){
    //         pq.push({it.second, it.first});
    //     }

    //     vector<string> ret;
    //     int tmp = 0;
    //     for(int i = 0; i < k; i++){
    //         ret.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     return ret;
    // }

    int k;
    void addWord(TrieNode *root, string word){
        TrieNode *cur = root;
        for(auto w : word){
            int t = w-'a';
            if(cur->next[t] == NULL){
                cur->next[t] = new TrieNode();
            }
            cur = cur->next[t];
        }
        cur->isEnd = true;
    }

    void getWord(TrieNode *root, string prefix, vector<string>&ret){
        if(!root) return;
        if(this->k == 0){
            return;
        }
        if(root->isEnd){
            ret.push_back(prefix);
            this->k--;
        }
        for(int i = 0; i < 26; i++){
            if(root->next[i] != NULL){
                getWord(root->next[i], prefix + (char)(i+'a'), ret);
            }
        }
        return ;

    }


    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>mp;
        this->k = k;
        for(auto &word : words){
            mp[word] += 1;
        }
        int n = words.size();
        vector<string> ret;
        vector<TrieNode*> bucket(n+1);
        for(int i = 0; i <= n; i++){
            TrieNode * newNode = new TrieNode();
            bucket[i] = newNode;
        }
        // cout << "n: " << n << endl;
        for(auto &it : mp){
            // cout << it.second << endl;
            // cout << it.first << endl;
            addWord(bucket[it.second], it.first);
        }

        for(int i = n; i >=0; i--){
            getWord(bucket[i], "", ret);
        }
        return ret;
    }
};