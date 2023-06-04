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
    approach 1: use count left side tree's nodes to decide go left or go right
    code :
    
        void find_left(TreeNode *root, int &depth){
        if(root==NULL)return ;
        else {
            depth++;
            find_left(root->left, depth);
            find_left(root->right, depth);
        } 
    }
    int find_ksmall(TreeNode *root, int k){
        int count = 0;
        find_left(root->left, count);
        if(k-1 == count)return root->val;
        else if(count > k-1){
            // rst in the left tree
            return find_ksmall(root->left, k);
        }
        else {
            return find_ksmall(root->right, k-count-1);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int rst = 0;
        rst = find_ksmall(root, k);
        return rst;
    }
    
    
    approach 2: inorder triverse is same as the ascending sort, so do the inorder triverse
    
    follow up question: insert and delete nodes in BST (701.)
    */
    int rst = 0;
    
    void inorder(TreeNode *root, int &k){
        if(root==NULL)return;
        inorder(root->left, k);
        if(--k == 0){
            rst = root->val;
        }
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return rst;
    }
};