/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string rst = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int level = q.size();
            for(int i = 0; i < level; i++){
                TreeNode *tp = q.front();
                q.pop();
                if(tp){
                    rst += (to_string(tp->val)+',');
                    if(tp->left) q.push(tp->left);
                    else q.push(NULL);
                    if(tp->right) q.push(tp->right);
                    else q.push(NULL);
                }
                else rst += "#,";

            }
        }
        // 1 \0 2 \0 3 \0 4 \0 5 \0 6 \0
        cout << rst << endl;
        return rst;
        
    }
    
    string helper(string& data){
        int spliter = data.find(',');
        string tp = data.substr(0, spliter);
        data = data.substr(spliter+1);
        
        return tp;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = NULL;
        
        queue<TreeNode*>q;
        string tp = helper(data);
        if(tp != "#"){
            root = new TreeNode(stoi(tp));
            q.push(root);
        }
        while(!q.empty()){
            int level = q.size();
            for(int i = 0; i < level; i++){
                TreeNode *tp = q.front();
                q.pop();
                string tp_left = helper(data);
                string tp_right = helper(data);
                TreeNode *left, *right;
                if (tp_left != "#") {left = new TreeNode(stoi(tp_left)); q.push(left);}
                else left = NULL;
                if(tp_right != "#") {right = new TreeNode(stoi(tp_right)); q.push(right);}
                else right = NULL;
                tp->left = left;
                tp->right = right;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));