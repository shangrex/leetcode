class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int rst = 0;
        
        while(left < right){
            rst = max(rst, (right-left)*min(height[right], height[left]));
            if(height[left] > height[right]){
                right--;
            }
            else left++;
        }
        return rst;
    }
};