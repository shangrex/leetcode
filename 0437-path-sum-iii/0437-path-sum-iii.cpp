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
 /*
 appraoch 1.
     int rst = 0;
    unordered_map<int, int>mp;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        findpath(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return rst;
    }

    void findpath(TreeNode*root, long long targetSum){
        if(!root) return;
        if(root->val == targetSum){
            rst++;
        }
        findpath(root->left, targetSum-root->val);
        findpath(root->right, targetSum-root->val);
    }
 */
class Solution {
public:
    /*
    Appraoch 1. DFS, be careful to count replicate. To count the new node, need to PathSum again

    Approach 2. prefix sum
    */
    int rst = 0;
    unordered_map<long long, long long>mp;
    int pathSum(TreeNode* root, int targetSum) {
        long long cur_sum = 0;
        mp[0] = 1;
        findpath(root, targetSum, cur_sum);
        return rst;
    }

    void findpath(TreeNode*root, long long targetSum, long long & cur_sum){
        if(!root) return;

        cur_sum += root->val;
        if(mp.find(cur_sum - targetSum) != mp.end()){
            rst += mp[cur_sum - targetSum];
        }
        mp[cur_sum] += 1;

        findpath(root->left, targetSum, cur_sum);
        findpath(root->right, targetSum, cur_sum);
        mp[cur_sum] -= 1;
        cur_sum -= root->val;
    }
};