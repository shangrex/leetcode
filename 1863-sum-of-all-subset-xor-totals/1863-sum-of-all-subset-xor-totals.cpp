class Solution {
public:
    void dfs(int index, vector<int>nums, vector<int>&elements){
        if(index > nums.size()-1)return;
        int tmp = elements.size();
        for(int j = 0; j < tmp; j++){
            elements.push_back(nums[index] ^ elements[j]);
        }
        dfs(index+1, nums, elements);

    }
    int subsetXORSum(vector<int>& nums) {
        vector<int>elements;
        elements.push_back(0);
        dfs(0, nums, elements);
        int ans = 0;
        for(int i = 1; i < elements.size(); i++){
            ans += elements[i];
        }
        return ans;
    }
};