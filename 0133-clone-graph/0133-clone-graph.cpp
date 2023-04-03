/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // DFS to triverse
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        
        // record the visited node
        vector<int>visit(101, 0);
        
        // transform original node to new copied node
        unordered_map<Node*, Node*>mp;
        
        // initialize dfs, and use dfs to triverse origin map
        stack<Node*> st;
        st.push(node);
        
        // construct initialize copied node
        Node *clone = new Node(node->val);
        mp[node] = clone; 
        
        while(!st.empty()){
            Node* cur = st.top();
            st.pop();
            // not visit
            if(visit[cur->val] == 0) {
                visit[cur->val] = 1;
                for(int i = 0; i < cur->neighbors.size(); i++){
                    // add not visited node nearby
                    if(visit[cur->neighbors[i]->val] == 0){
                        st.push(cur->neighbors[i]);
                    }
                    
                    // construct copied node and connect
                    if(mp.find(cur->neighbors[i]) == mp.end()){
                        Node* clone = new Node(cur->neighbors[i]->val);
                        mp[cur->neighbors[i]] = clone;
                    }
                    mp[cur]->neighbors.push_back(mp[cur->neighbors[i]]);
                }
            }
        }
        return mp[node];
    }
};