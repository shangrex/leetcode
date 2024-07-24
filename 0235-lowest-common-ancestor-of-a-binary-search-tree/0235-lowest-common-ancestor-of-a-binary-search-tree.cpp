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
    Time: O(H), the height of the tree
    Space: O(1)
    */
    TreeNode* lca(TreeNode*root, int left, int right){
        if(!root)return NULL;
        if(root->val == left || root->val == right)return root;
        if(root->val >= left && root->val <= right){
            return root;
        }
        else if(root->val > right){
            return lca(root->left, left, right);
        }
        else {
            return lca(root->right, left, right);
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)swap(p, q);
        return lca(root, p->val, q->val);
    }
};