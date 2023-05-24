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
    special technique NULL+3 = 3
    be aware of sequence feature (dfs can not return left node + right node + middle value) 
    !! we should be aware of the return value of the dfs
    */
    int treesum(TreeNode* root, int &rst){
        if(root == NULL)return NULL;
        int left = 0, middle = 0, right = 0;
        middle = root->val;
        // the sequence in the left node
        left = treesum(root->left, rst);
        
        // the sequence in the right node
        right = treesum(root->right, rst);
        
        int tmp, seq;
        // return the sequence value, and the sequence should not repeated so only left or right can choose
        seq = max({left+middle, middle, right+middle});
        // choose the biggest value and store to rst
        tmp = max(seq, left+middle+right);
        rst = max(tmp, rst);
        
        return seq;
    }
    int maxPathSum(TreeNode* root) {
        int rst = -INT_MAX;
        treesum(root, rst);
        return rst;
    }
};