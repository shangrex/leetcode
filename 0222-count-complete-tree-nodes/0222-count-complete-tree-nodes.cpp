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
    void dfs(TreeNode *root, int &ret){
        if(!root) return;
        ret++;
        dfs(root->left, ret);
        dfs(root->right, ret);
    }
    int countNodes(TreeNode* root) {
        int ret = 0;
        dfs(root, ret);
        return ret;
    }
};