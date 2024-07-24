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
    void dfs(TreeNode*root , int &rst, int max_val){
        if(!root)return;
        cout << root->val << " " << max_val << endl;
        if(root->val >= max_val)rst+=1;
        if(root->val > max_val) max_val = root->val;
        if(root->left)dfs(root->left, rst, max_val);
        if(root->right)dfs(root->right, rst, max_val);
    }
    
    int goodNodes(TreeNode* root) {
        int rst = 0;
        dfs(root, rst, root->val);
        return rst;
    }
};