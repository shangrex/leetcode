class Solution {
public:
    /*
    topology sort to check the lexicographical order and check if there is cycle
    
    be careful about the definiton of lexicographical order.
    we are checking character by character to see where the mismatch happens first and using that to create edges.
    and notice there is a failed input, the prefix should be first, but the test case have "abc" "ab", so in this failed case, we should out put "" not cab
    
    */
    string alienOrder(vector<string>& words) {
        if(words.size() == 0)return "";
        unordered_map<char, int>indegree;
        unordered_map<char, unordered_set<char>>graph;
        
        // initialize
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                indegree[words[i][j]] = 0;
            }
        }
        
        // build graph
        for(int i = 0; i < words.size() - 1; i++){
            string cur = words[i];
            string next = words[i+1];
            int tmp = min(cur.length(), next.length());
            for(int j = 0; j < tmp; j++){
                if(cur[j] != next[j]){
                    if(graph[cur[j]].count(next[j]) == 0){
                        indegree[next[j]]++;
                        graph[cur[j]].insert(next[j]);
                    }
                    break;
                }
            }
            if(cur.find(next) == 0 && cur.length() > next.length()){
                cout << "invalid input" << endl;
                return "";
            }
        }
        // topology sort
        queue<int>q;
        string ans = "";
        
        for(auto i : indegree){
            if(i.second == 0){
                q.push(i.first);
            }
        }
        
        while(!q.empty()){
            char c = q.front();
            ans += c;
            q.pop();
            for(auto &i : graph[c]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }                
            
        }
        
        return ans.length() == indegree.size() ? ans : "";
    }
};