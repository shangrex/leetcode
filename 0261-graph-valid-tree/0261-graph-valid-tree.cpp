class Solution {
public:
    unordered_map<int, int>mp;
    bool Union(int a, int b){
        int root_a = Find(a);
        int root_b = Find(b);
        if(root_a == root_b) return false;
        mp[root_b] = root_a;
        return true;
    }
    
    int Find(int a){
        if(mp[a] == a)return a;
        else return Find(mp[a]);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++){
            mp[i] = i;
        }
        for(auto &edge : edges){
            bool check = Union(edge[0], edge[1]);
            if(!check) return false;
        }
        
        int count_one_root = 1;
        for(auto i : mp){
            if(i.first == i.second) count_one_root --;
        }
        if(count_one_root == 0)return true;
        else return false;
    }
};