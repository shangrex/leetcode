/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    1. BFS, the last element in each level

       vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int>rst;
        // dfs(root, rst);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            for(int i = 0; i < level; i++){
                TreeNode*t = q.front();
                if(i == level-1){
                    rst.push_back(t->val);
                }
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return rst;
    }


    2. DFS, 
    mid, right , left.
    each level down, the fist element in that level

    */







    void dfs(TreeNode*root, vector<int>&rst, int level){
        if(!root)return;
        if(rst.size() == level) rst.push_back(root->val);
        dfs(root->right, rst, level + 1);
        dfs(root->left, rst, level + 1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>rst;
        dfs(root, rst, 0);
        return rst;
    }
};