class Solution {
public:
    /*
    method 1 bruce force 
    Time O(N)
    the finised meeting must connect a earliest meeting.
    1. sort the array with the first element
    2. create a two dimension vector to save the ending time of the meeting
    3. if the new meeting times can not arranged in the ending time in step 2 then create a new meeing room
    
    method 2 min heap
    Time O(NlgN)
    1. create a min heap
    2. if the new meeting is begger than the smallest ending time then push one heap 
    else alter the smallest heap value
    
    method 3 seperate record the starting and ending times, because the there must be a staring time before ending time, and we sorted with the starting time.
    
    */
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // the info of the priority_queue https://yuihuang.com/cpp-stl-priority-queue/
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
           return a[0] < b[0]; 
        });
        int rst = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(min_heap.empty()){
                rst++;
                min_heap.push(intervals[i][1]);
            }
            else if(min_heap.top() <= intervals[i][0]){
                min_heap.pop();
                min_heap.push(intervals[i][1]);
            }
            else {
                rst++;
                min_heap.push(intervals[i][1]);
            }
        }
        
        return rst;
    }
};