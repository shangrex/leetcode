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
    int findMaxFromLeft(TreeNode* root){
        int tmpMax = root->val;
        TreeNode *cur = root;
        while(cur){
            if(tmpMax < cur->val){
                tmpMax = cur->val;
            }
            cur = cur->right;
        }
        return tmpMax;
    }
    TreeNode* findKey(TreeNode *root, int key){
        if(!root){
            return NULL;
        }
        else if(root->val > key){
            root->left = findKey(root->left, key);
        }
        else if(root->val < key){
            root->right = findKey(root->right, key);
        }
        else {
            if(!root->left && !root->right){
                delete(root);
                root = NULL;
            }
            else if(!root->left) root = root->right;
            else if(!root->right) root = root->left;
            else {
                // replace 
                root->val = findMaxFromLeft(root->left);
                root->left = findKey(root->left, root->val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = findKey(root, key);
        return root;
    }
};