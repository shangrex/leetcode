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
    Trivese the tree with BST rule, when it go to the leaf then insert the node.
    */
    void bst(TreeNode *root,int val){
        if(val > root->val){
            if(root->right)
                bst(root->right, val);
            else{
                TreeNode *tmp = new TreeNode(val);
                root->right = tmp;
            }
        }
        else {
            if(root->left)
                bst(root->left, val);
            else {
                TreeNode *tmp = new TreeNode(val);
                root->left = tmp;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        bst(root, val);
        return root;
    }
};