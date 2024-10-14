class Solution {
public:
    
    unordered_map<int, int>mp;
    int rst = 0;
    int Find(int a){
        if(mp[a] == a) return a;
        else return Find(mp[a]);
    }
    
    void Union(int a, int b){
        int root_a = Find(a);
        int root_b = Find(b);
        if(root_a != root_b) {cout << root_a << " " << root_b << endl;this->rst--;mp[root_b] = root_a;}
        
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++){
            mp[i] = i;
        }
        this->rst = n;
        for(auto &edge : edges){
            Union(edge[0], edge[1]);
        }
        
        // for(int i = 0; i < n; i++){
        //     if(mp[i] == i){cout << i << endl;this->rst++;}
        // }
        return this->rst;
    }
};