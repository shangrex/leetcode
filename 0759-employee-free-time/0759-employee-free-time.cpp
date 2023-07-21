/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    /*
    apporach 1: heap
    approach 2: Sweep-line algorithm
    Free time is a period of time such that no employees scheduled to work, i.e. the gap between every two non-overlapping intervals. If we meet a start of interval, score++; or else(if we meet an end of interval), score--. Non-overlapping intervals exist when score equals to 0.
    reference: https://leetcode.com/problems/employee-free-time/discuss/175081/Sweep-line-Java-with-Explanations

    
    */
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<pair<int, int> >pr;
        for(int i = 0; i < schedule.size(); i++){
            for(auto j : schedule[i]){
                pr.push_back({j.start, j.end});
            }
        }
        sort(pr.begin(), pr.end(), [](pair<int, int>first, pair<int, int>second){
            if(first.first < second.first)return true;
            else if(first.first == second.second){
                return first.second < second.second;
            }
            else return false;
        });
        
        int last_end = -1;
        vector<Interval> rst;
        
        for(auto i : pr){
            // the first one
            if(last_end == -1){
                last_end = i.second;
            }
            else {
                // intervals happens
                if(i.first > last_end){
                    rst.push_back(Interval(last_end, i.first));
                    last_end = i.second;
                }
                else {
                    last_end = max(last_end, i.second);
                }
            }
        }
        return rst;
    }
};