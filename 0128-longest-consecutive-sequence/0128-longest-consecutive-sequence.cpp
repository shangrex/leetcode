class Solution {
/*
method 1: union find
the head of the union is the smallest number of the set, and the set can connect if the element's value difference is 1

method 2: set, 
add all element into set, and used hashtable to check the longest continuouse sequence
*/    
public:
    // union set data structure
    unordered_map<int, int> mp;
    // count the set size
    unordered_map<int, int> mp_size;
    //initialize the union set
    void init(int value){
        mp[value] = value;
        mp_size[value] = 1;
    }
    
    // union the two set 
    void Union(int a, int b){
        // a  b=(a-1)
        int head_a = Find(a);
        int head_b = Find(b);
        mp[head_a] = head_b;
        mp_size[head_b] += mp_size[head_a];
    }
    
    // return the head of the union set
    int Find(int value){
        if(mp[value] == value) return value;
        return Find(mp[value]);
    }
    
    int longestConsecutive(vector<int>& nums) {
        // initialize the union set
        for(int i = 0; i < nums.size(); i++){
            init(nums[i]);
        }
        for(auto i : mp){
            // exist value - 1
            if(mp.count(i.first-1) != 0){
                Union(i.first, i.first-1);
            }
        }
        int rst = 0;
        for(auto i : mp_size){
            //cout << i.first << " " << i.second << endl;
            rst = max(rst, i.second);
        }
        
        return rst;
    }
};