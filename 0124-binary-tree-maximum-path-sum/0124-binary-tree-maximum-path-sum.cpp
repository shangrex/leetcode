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
    int dfs(TreeNode* root, int &rst){
        if(!root) return NULL;
        int middle = root->val;
        int left = dfs(root->left, rst);
        int right = dfs(root->right, rst);
        int seq = max({left+middle, right+middle, middle});
        int tmp = max({seq, left+right+middle});
        rst = max(tmp, rst);
        return seq;
    }
    int maxPathSum(TreeNode* root) {
        int rst = -INT_MAX;
        dfs(root, rst);
        return rst;
    }
};