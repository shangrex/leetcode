class SparseVector {
public:
    /*
    (Not accept by Meta interivew)Approach 1. hash map to store non value index in first vector 
    and calculate 

    time complexity O(N) for creating hash table, O(L) for calcualteing
    space complextiy O(L) hash table, only store non-zero


    unordered_map<int, int>mp;

    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                mp[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int rst = 0;
        for(auto it : this->mp){
            if(vec.mp.find(it.first) != vec.mp.end()){
                rst += it.second * vec.mp[it.first];
            }
        }

        return rst;
    }


    Appoach 2. two pointer + pair
    */

    vector<pair<int, int>>vp;
    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                vp.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int left = 0, right = 0;
        int rst = 0;
        while(left < vp.size() && right < vec.vp.size()){
            cout << left << right << endl;
            cout << vp[left].first << " " << vec.vp[right].first << endl;
            if(vp[left].first == vec.vp[right].first){
                rst += vp[left].second * vec.vp[right].second;
                left++;
                right++;
            }
            else if(vp[left].first > vec.vp[right].first){
                right++;
            }
            else left++;
        }

        return rst;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);