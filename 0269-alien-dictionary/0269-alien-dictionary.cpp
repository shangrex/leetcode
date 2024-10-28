class Solution {
public:
        /*
    topology sort to check the lexicographical order and check if there is cycle
    
    be careful about the definiton of lexicographical order.
    we are checking character by character to see where the mismatch happens first and using that to create edges.
    and notice there is a failed input, the prefix should be first, but the test case have "abc" "ab", so in this failed case, we should out put "" not cab
    
    topology sort
    1. construct graph and indegree
    2. push indegree 0 to queue
    3. bfs and if indegree == 1 then add it to queue, then indegree--
    */
    string alienOrder(vector<string>& words) {
        unordered_map<char, set<char> >graph;
        unordered_map<char, int>indegree;
        
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                indegree[words[i][j]] = 0;
            }
        }
        
        for(int i = 0 ; i < words.size()-1; i++){
            string cur = words[i];
            string next = words[i+1];
            if(cur.find(next) == 0 && cur.length() > next.length()){
                return "";
            }
            for(int j = 0; j < min(cur.length(), next.length()); j++){
                if(cur[j] != next[j]){
                   if(graph[cur[j]].count(next[j]) == 0){
                        graph[cur[j]].insert(next[j]);
                        indegree[next[j]] += 1;
                    }
                    
                    break;
                }
            }
        }
        
        
        queue<char> q;
        for(auto & i : indegree){
            if(i.second == 0){
                cout << i.first << endl;
                q.push(i.first);
            }
        }
        
        string ans = "";
        while(!q.empty()){
            char t = q.front();
            ans += t;
            q.pop();
            for(auto &s : graph[t]){
                cout << s << indegree[s] << endl;
               if(--indegree[s] == 0){
                    q.push(s);
                }
            }
        }
        return ans.size() == indegree.size() ? ans : "";
    }
};