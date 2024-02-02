class Solution {
public:
    /*
        int rst=0;
        int l = 0, r = height.size()-1, hr, hl;
        while(l<r){
            hl = height[l];
            hr = height[r];
            rst = max(rst, (r-l)*min(hl, hr));
            if(hl < hr)l++;
            else r--;
        }
        return rst;
    */
    int maxArea(vector<int>& height) {
        int rst = 0;
        int l = 0, r = height.size()-1;
        while(l < r){
            rst = max(rst, (r-l) * min(height[l], height[r]));
            if(height[r] > height[l])l++;
            else r--;
        }
        return rst;
    }
};