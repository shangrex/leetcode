class Solution {
public:
    /*
    method 1 union find to find if there is cycle
    */
    unordered_map<int, int>mp;
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // initialize
        for(int i = 0;i < n; i++){
            mp[i] = i;    
        }
        // check if there is cycle
        for(int i = 0;i < edges.size(); i++){
            bool check = Union(edges[i][0], edges[i][1]);
            if(check == false)return false;
        }
        // check the isolated nodes
        int tmp = 0;
        for(auto i : mp){
            if(i.second == i.first)tmp++;
        }
        if(tmp > 1)return false;
        
        return true;
    }
    bool Union(int a, int b){
        int head_a = Find(a);
        int head_b = Find(b);
        if(head_a == head_b) return false;
        mp[head_b] = head_a;
        return true;
    }
    int Find(int value){
        if(mp[value] == value)return value;
        else return Find(mp[value]);
    }
};