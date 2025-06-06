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
/*
class Solution {
public:
    unordered_map<Node*, Node*>mp;
    Node* dfs(Node*node, vector<int>&visited){
        if(node == NULL){
            return NULL;
        }
            Node *new_node = new Node(node->val);
            mp[node] = new_node;
            visited[node->val] = 1;
        cout << node->val << endl;
        for(int i = 0; i < node->neighbors.size(); i++){
            Node *tmp;
            if(visited[node->neighbors[i]->val] == 0)
                tmp =  dfs(node->neighbors[i], visited);
            else tmp = mp[node->neighbors[i]];
            mp[node]->neighbors.push_back(tmp);
        }
        return mp[node];
    }
    Node* cloneGraph(Node* node) {
        vector<int>visited(101, 0);
        dfs(node, visited);
        return mp[node];
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*>mp;
    Node* dfs(Node*node, vector<int>&visited){
        if(!node) return NULL;
        Node* new_node = new Node(node->val);
        visited[node->val] = 1;
        mp[node] = new_node;
        for(int i = 0; i < node->neighbors.size(); i++){
            if(visited[node->neighbors[i]->val] == 0){
                Node *tmp = dfs(node->neighbors[i], visited);
                new_node->neighbors.push_back(tmp);
            } else{
                new_node->neighbors.push_back(mp[node->neighbors[i]]);
            }
        }
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        vector<int>visited(101, 0);
        dfs(node, visited);
        return mp[node];
    }
};