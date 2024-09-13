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
    Very Very Important question !!!
    
    Divide and conquer algorithmns
    
    preorder feature: vector[0] will always be the root
    inorder feature: vector[index], all the left tree is in vector[0:index], and the right tree is in vector[index, vector.size()-1]
    
    root_index pass by reference
    
    */
    TreeNode *build(vector<int>&preorder, vector<int>&inorder, int& idx, int left, int right){
        if(left > right) return NULL;
        if(idx >= preorder.size()) return NULL;
        cout << idx << " " << left << " " << right << endl;
        TreeNode *root = new TreeNode(preorder[idx]);
        int split_point = -1;
        for(int i = left; i <= right; i++){
            if(inorder[i] == preorder[idx]){
                split_point = i;
                break;
            }
        }
        idx++;
        root->left = build(preorder, inorder, idx, left, split_point-1);
        root->right = build(preorder, inorder, idx, split_point+1, right);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* head;
        int idx = 0;
        head = build(preorder, inorder, idx, 0, inorder.size()-1);
        return head;
    }
};