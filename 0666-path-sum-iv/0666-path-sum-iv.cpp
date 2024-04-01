class Solution {
public:
    
    void dfs(vector<int>&tree, int cur, int &rst_sum, int path_sum){
        // condition exit
        path_sum += tree[cur];
        if(tree[cur*2+1] < 0 && tree[cur*2+2] < 0){
            rst_sum += path_sum;
            return;
        }
        
        // left node
        if(tree[cur*2+1] >= 0)dfs(tree, cur*2+1, rst_sum, path_sum);
        // right node
        if(tree[cur*2+2] >= 0)dfs(tree, cur*2+2, rst_sum, path_sum);
        
    }
    
    // 1. construct the tree
    // 2. dfs add the path sum
    int pathSum(vector<int>& nums) {
        //      3   -> 0
        //    5   1 -> 1
        //  2  4 4  2  ->3
        //  result : (3+5+2) + (3+5+4) + ()
        // 2 -> 312 -> position -> 3 
        // construct tree
        // the index of the tree is position
        // left child of the mother node(i) should be i*2+1 
        // right child of the mother node(i) should be i*2+2
        // the value of the tree is value
        // 2^4 -> 16
        vector<int>tree(32, -1);
        
        for(int i = 0; i < nums.size(); i++){
            int hundred = (nums[i] / 100);
            int ten = (nums[i]) % 100 /10;
            int unit = (nums[i]) %10;
            tree[pow(2, (hundred-1)) + ten-1 -1] = unit;
        }
        int rst_sum = 0, path_sum = 0;
        dfs(tree, 0, rst_sum, path_sum);
        return rst_sum;
        

        
    }
};