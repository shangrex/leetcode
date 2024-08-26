class Solution {
public:
    /*
    Key points: choose most frequency time can lead to less idle time
    
    Approach 1. priority queue
    Approach 2. formula
    
    
    good reference: https://leetcode.com/problems/task-scheduler/discuss/3280549/Full-explanation-or-Using-Priority-Queue-and-Formula-based-Approach
    */
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> freq;
        priority_queue<int> p;
        
        for(auto & task : tasks){
            freq[task]++;
            // cout << freq[task] << endl;
        }
        
        for(auto task : freq){
            p.push(task.second);
        }
        
        
        int rst = 0;
        while(!p.empty()){
            vector<int> remain;
            int task_cnt = 0;
            while(!p.empty() && task_cnt < n+1){
                int t = p.top();
                if(t > 1){
                    t--;
                    remain.push_back(t);
                }
                p.pop();
                task_cnt++;
            }
            
            for(auto j : remain){
                p.push(j);
            }
            if(!p.empty()) task_cnt = n+1;
            int r = task_cnt;
            rst += r;
        }
        
        return rst;
    }
};