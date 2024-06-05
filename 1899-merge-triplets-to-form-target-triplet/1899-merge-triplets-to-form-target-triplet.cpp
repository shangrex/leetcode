class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>rst(3, 0);
        for(auto triplet : triplets){
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                rst = {max(rst[0], triplet[0]), max(rst[1],triplet[1]), max(rst[2], triplet[2])};
            }
        }
        if(rst[0] == target[0] && rst[1] == target[1] && rst[2] == target[2]){
            return true;
        }
        return false;
    }
};