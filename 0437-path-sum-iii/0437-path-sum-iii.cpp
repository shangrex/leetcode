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
    void helper(TreeNode* root, long long int sum, int &ans, unordered_map<long long int, long long int>mp, int target){
        if(!root)return;
        // 10 15 18 21
        sum += root->val;
        
        
        if(mp.find(sum-target) != mp.end()){
            if(mp[sum-target] > 0)ans += mp[sum-target];
        }
        
        // add prefix sum 
        if(mp.find(sum) != mp.end()){
            mp[sum]+=1;
        }
        else {
            cout << sum << endl;
            mp[sum] = 1;
        }
        
        // triverse
        helper(root->left, sum, ans, mp, target);
        helper(root->right, sum, ans, mp, target);
        
        // remove prefix
        mp[sum] -= 1;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long int, long long int>mp; // key: value, value: count
        mp[0] = 1;
        helper(root, 0, ans, mp, targetSum);
        return ans;
    }
};