class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());

        int leftIdx = 0, rightIdx = warehouse.size()-1;
        int boxIdx = boxes.size()-1;
        int ret = 0;
        while(leftIdx <= rightIdx && boxIdx >= 0){
            if(boxes[boxIdx] <= warehouse[leftIdx]){
                leftIdx++;
                ret++;
            }
            else if(boxes[boxIdx] <= warehouse[rightIdx]){
                rightIdx--;
                ret++;
            }
            boxIdx--;
        }
        return ret;
    }
};