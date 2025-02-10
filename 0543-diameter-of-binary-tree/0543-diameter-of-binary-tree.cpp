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

/*
    int dfs(TreeNode *root, int level, int &rst){
        if(!root)return 0;
        int left = dfs(root->left, level+1, rst);
        int right = dfs(root->right, level+1, rst);
        if(level != 0)rst = max(rst, left+right+1);
        return max(left+1, right+1);
    }
        int diameterOfBinaryTree(TreeNode* root) {
        int rst = 0;
        dfs(root, 0, rst);
        return rst;
    }
*/









class Solution {
public:

    int dfs(TreeNode *root, int &ret, int level){
        if(!root) return 0;
        int left = dfs(root->left, ret, level);
        int right = dfs(root->right, ret, level);
        level = max(left, right)+1;
        ret = max(ret, left+right);
        return level;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;
        int level = dfs(root, ret, 0);
        return ret;
    }
};