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
    int dfs(TreeNode *root, int rst){
        if(root!=NULL)rst++;
        else return rst;
        int left = dfs(root->left, rst);
        int right = dfs(root->right, rst);
        return left>right?left:right;
    }
    int maxDepth(TreeNode* root) {
        int rst = 0;
        rst = dfs(root, rst);
        return rst;
    }
};