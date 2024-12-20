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
        0
    1       2
   0. 0.   0. 0
 1. 1 1 1 2 2 2 2

         0
    1       2
   0. 0.   0. 0
 2. 2 2 2 1 1 1 1
 */
class Solution {
public:
    void dfs(TreeNode* root, int level){
        if(!root) return;
        cout << level << endl;
        if(level % 2 == 0 && root->left && root->right) {
            cout << root->left->val << " " << root->right->val << endl;
            swap(root->left->val, root->right->val);
        }
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int s_size = q.size();
            vector<int>st;
            vector<TreeNode*>tst;
            for(int i = 0; i < s_size; i++){
                TreeNode *t = q.front();
                q.pop();
                if(t->left) {tst.push_back(t->left);st.push_back(t->left->val);}
                if(t->right) {tst.push_back(t->right);st.push_back(t->right->val);}
            }

            if(level % 2 == 0){
                reverse(st.begin(), st.end());
            }
            for(int i = 0; i < tst.size(); i++){
                cout << st[i] << " " << st[i];
                tst[i]->val = st[i];
                q.push(tst[i]);
            }
            cout << endl;
            level++;
        }
        return root;
    }
};