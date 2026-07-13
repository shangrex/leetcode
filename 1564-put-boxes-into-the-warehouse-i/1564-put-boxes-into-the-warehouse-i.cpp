class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());

        int tmpMin = INT_MAX;
        for(int i = 0; i < warehouse.size(); i++){
            tmpMin = warehouse[i] = min(warehouse[i], tmpMin);
        }

        int ret = 0;
        for(int i = warehouse.size()-1; i>=0; i--){
            if( ret < boxes.size() && boxes[ret] <= warehouse[i]){
                ret++;
            }
        }
        return ret;
    }
};