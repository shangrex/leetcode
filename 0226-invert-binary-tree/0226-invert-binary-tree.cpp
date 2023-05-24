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
    void invert(TreeNode* tree){
        if(tree == NULL)return ;
        swap(tree->left, tree->right);
        invert(tree->left);
        invert(tree->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};