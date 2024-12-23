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
    cycle sort: in-place sort
    */
    int minimumOperations(TreeNode* root) {
        int ans = 0;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int level_length = q.size();
            vector<int>v(level_length);
            for(int i = 0; i < level_length;i++){
                TreeNode* tp = q.front();
                q.pop();
                v[i] = tp->val;
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
            }

            ans += getMinSwaps(v);

        }

        return ans;
    }

private:
    int getMinSwaps(vector<int>&v){
        // 7 6 8 5
        // 0 1 2 3
        // 5 6 8 7

        // 5 6 7 8
        int ans = 0;
        unordered_map<int, int>mp;
        for(int i = 0; i < v.size(); i++){
            mp[v[i]] = i;
        }
        vector<int>tp_v = v;
        sort(tp_v.begin(), tp_v.end());
        for(int i = 0; i < tp_v.size(); i++){
            if(tp_v[i] != v[i]){
                // cout << tp_v[i] << " " << v[i] << endl;
                // cout << mp[tp_v[i]] << " " << mp[v[i]] << endl;
                int t = v[i];
                swap(v[i], v[mp[tp_v[i]]]);
                swap(mp[v[i]], mp[t]);
                //cout << "swapping" << v[i] << v[mp[tp_v[i]]] << endl;
                ans++;
            }
            // for(auto j : v) cout << j ;
            // cout << endl;
        }
        return ans;
    }
};