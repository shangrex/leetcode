/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /*
    Notice BST feature, lca node is between the node value
    Just walk down from the whole tree's root as long as both p and q are in the same subtree (meaning their values are both smaller or both larger than root's). 
    */
    TreeNode* lca(TreeNode* root, TreeNode*p, TreeNode* q){
        if(p->val > root->val && q->val > root->val){
            return lca(root->right, p, q);   
        }
        else if(p->val < root->val && q->val < root->val){
            return lca(root->left, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};