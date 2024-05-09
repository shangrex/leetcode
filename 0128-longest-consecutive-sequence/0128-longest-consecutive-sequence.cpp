class Solution {
public:
    
    unordered_map<int, int> mp;
    unordered_map<int, int> mp_size;
    
    int Find(int a){
        if(mp[a] == a)return a;
        else return Find(mp[a]);
    }
    
    void Union(int a, int b){
        int root_a = Find(a);
        int root_b = Find(b);
        mp[root_a] = root_b;
        mp_size[root_b] += mp_size[root_a];
    }
    
    int longestConsecutive(vector<int>& nums) {
        // 1. Construct union
        for(auto num : nums){
            mp[num] = num;
            mp_size[num] = 1;
        }
        
        
        // 2. Union the graph
        for(auto i : mp){
            if(mp.find(i.second-1) != mp.end()){
                Union(i.second, i.second-1);
            }
        }
        
        
        // 3. Find the longest legnth
        int rst = 0;
        for(auto i : mp_size){
            rst = max(rst, i.second);
        }
        return rst;
        
    }
};