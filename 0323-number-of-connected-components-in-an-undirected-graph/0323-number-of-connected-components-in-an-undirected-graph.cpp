class Solution {
public:
    /*
    method 1 use union find
    
    */
    unordered_map<int, int>mp;
    
    int countComponents(int n, vector<vector<int>>& edges) {
        // initialize
        for(int i = 0;i < n; i++){
            mp[i] = i;
        }
        
        for(int i = 0;i < edges.size(); i++){
            bool check = Union(edges[i][0], edges[i][1]);
            if(check)n--;
        }
        return n;
    }
    
    bool Union(int a, int b){
        int head_a = Find(a);
        int head_b = Find(b);
        if(head_a != head_b){
            mp[head_b] = head_a;
            return true;
        }
        else return false;
        
    }
    
    int Find(int value){
        if(mp[value] == value)return value;
        else return Find(mp[value]);
    }
};