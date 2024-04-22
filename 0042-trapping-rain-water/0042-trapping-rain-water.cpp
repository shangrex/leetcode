class Solution {
public:
    /*
    Approach 1. 
    iterate throught the height, in each iteration find min(max left , max right), and this is the height[i] can trapped the water
    
    Approach 2.
    
    */
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int rst = 0, left_max = height[left], right_max = height[right];
        while(left < right){
            if(height[right] > height[left]){
                if(left_max > height[left]) rst += ( left_max - height[left]);
                left++;
                left_max = max(left_max, height[left]);
            }
            else {
                if(right_max > height[right]) rst += (right_max - height[right]);
                right --;
                right_max = max(right_max, height[right]);
            }
        }
        return rst;
    }
};