class SparseVector {
public:
    unordered_map<int, int>mp;

    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
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
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);