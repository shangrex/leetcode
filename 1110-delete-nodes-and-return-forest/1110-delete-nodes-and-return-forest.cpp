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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ret;
        set<int> deleted;
        for(auto & i : to_delete){
            deleted.insert(i);
        }

        helper(root, ret, deleted, true);
        return ret;
    }

private:
    TreeNode* helper(TreeNode *cur, vector<TreeNode*>&ret, set<int>& deleted, bool isRoot){
        if(!cur) return NULL;
        bool isDelete = deleted.count(cur->val) > 0 ? true : false;
        if(!isDelete && isRoot){
            ret.push_back(cur);
        }

        cur->left = helper(cur->left, ret, deleted, isDelete);
        cur->right = helper(cur->right, ret, deleted, isDelete);
        return isDelete ? NULL : cur;
    }
};