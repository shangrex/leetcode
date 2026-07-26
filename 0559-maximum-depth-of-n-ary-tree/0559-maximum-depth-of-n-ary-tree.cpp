/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node *cur, int level, int &ret){
        if(!cur) return;
        ret = max(ret, level);
        for(int i = 0; i < cur->children.size(); i++){
            dfs(cur->children[i], level+1, ret);
        }
    }
    int maxDepth(Node* root) {
        int level = 1, ret = 0;
        dfs(root, level, ret);
        return ret;
    }
};