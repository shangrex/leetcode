class Solution {
public:
    
    unordered_map<int, int> mp;
    unordered_map<int, int> mp_size;
    
    int find(int a){
        if(mp[a] == a)return a;
        return find(mp[a]);
    }
    
    void Union(int a, int b){
        // a = b-1
        int head_a = find(a);
        int head_b = find(b);
        
        mp[head_b] = head_a;
        mp_size[head_a] += mp_size[head_b];
    }
    
    int longestConsecutive(vector<int>& nums) {
        int rst = 0;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = nums[i];
            mp_size[nums[i]] = 1;
        }
        
        for(auto i : mp){
            if(mp.find(i.second-1) != mp.end()){
                Union(i.second-1, i.second);
            }
        }
        
        for(auto i : mp_size){
            rst = max(rst, i.second);
        }
        
        return rst;
    }
};