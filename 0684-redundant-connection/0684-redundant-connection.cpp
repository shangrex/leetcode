class Solution {
public:
    unordered_map<int, int>mp;
    
    int Join(int a, int b){
        int root_a = Find(a);
        int root_b = Find(b);
        
        if(root_a == root_b)return false;
        if(root_a < root_b){
            mp[root_b] = root_a;
        }
        else {
            mp[root_a] = root_b;
        }
        return true;
    }
    
    int Find(int a){
        if(mp[a] == a)return a;
        else return Find(mp[a]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // init the union
        for(int i = 1; i <= n; i++){
            mp[i] = i;
        }
        vector<int>rst;
        // construct the graph
        for(int i = 0; i < n; i++){
            if(!Join(edges[i][0], edges[i][1])){
                rst = edges[i];
            }
        }
        return rst;
    }
};