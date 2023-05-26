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
    
    
    */
    
    TreeNode* check(vector<int> &preorder, vector<int>&inorder, int &root_index, int left_bound, int right_bound){
        if(left_bound > right_bound)return NULL;
        
        TreeNode *root = new TreeNode(preorder[root_index]);
        
        int pivot=left_bound;
        for(int i = left_bound; i <= right_bound; i++){
            if(preorder[root_index] == inorder[i]){
                pivot = i;
                break;
            }
        }
        // root_index should pass by reference, since every root node would only calculate once.
        root_index++;
        // pass inorder left_bound and right bound
        root->left = check(preorder, inorder, root_index , left_bound, pivot-1);
        root->right = check(preorder, inorder, root_index, pivot+1, right_bound);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root_index=0;
        return check(preorder, inorder, root_index, 0, preorder.size()-1);
    }
};