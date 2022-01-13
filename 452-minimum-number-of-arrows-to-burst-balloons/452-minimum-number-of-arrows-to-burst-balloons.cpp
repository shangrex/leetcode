class Solution {
public:
    /*
    minimum arrows -> hit the most cover
    ->hit the isolated number
    [1,6][2,8][7,12][10,16]
    [2,6][7,12][10,16] ++
    [7,12][10,16]
    
    A1.
    Use greedy to find the cover places, if the new points is not in cover then add 1 shoot.
    Initialze shoot with 1.
    
    A2. Sorted with the Xend value, and shoot as right as possible.
    
    Important things: !!!! compare operator use pass by reference would pass otherwise would get TLE!!!!
    Other comments: For simple types like int, passing by value might be faster, but for more complex types like vectors it should be faster to pass by reference to avoid the copy. 
    */
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())return 0;
        
        //sort right value
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1]?true:false;
        });
        int rst = 1, maxp = points[0][1];
        for(auto i : points){
            if(i[0] > maxp){
                rst++;
                maxp = i[1];
            }
        }       
        
        return rst;
    }
};