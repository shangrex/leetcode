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
    
    A1
    1. know the level of tree
    2. add the number to the 2 power
    3. triverse with dfs and add
    
    A2
    1. val will multiply to the level number to the 2 power
    2. sum all val
    */
    int mpow(int a, int b){
        if(b==0)return 1;
        int rst=1;
        for(int i = 0; i < b; i++){
            rst*=a;
        }
        return rst;
    }
    int dfs(TreeNode* root, string num, int level, int sum){
        if(root->left == NULL && root->right == NULL){
            num += to_string(root->val);
            for(int i = 0; i < num.length(); i++){
                sum += (num[i]-'0')*mpow(2, num.length()-i-1);
            }
        }
        if(root->left != NULL) sum += dfs(root->left, num+to_string(root->val), level+1, 0);
        if(root->right != NULL)sum += dfs(root->right, num+(to_string(root->val)), level+1, 0);
        return sum;

    }
    int sumRootToLeaf(TreeNode* root) {
        int sum = dfs(root, "", 1, 0);
        return sum;
    }
};