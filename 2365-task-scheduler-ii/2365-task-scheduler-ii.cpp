class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {

        /*
            1 2 1 2 3 1
            0 1 2 3 4 5
            0 1 2
                3
                5 6 

        5 8 8 5
        1 2
            
        */
        long long ret = 0;
        unordered_map<long, long> mp;
        for(int i = 0; i < tasks.size(); i++){
            if(mp.find(tasks[i]) == mp.end()){
                ret++;
                mp[tasks[i]] = ret+space;
            }
            else{
                if(mp[tasks[i]] >= ret){
                    ret = (mp[tasks[i]]+1);
                }
                else{
                    ret++;
                }
                mp[tasks[i]] = ret+space;
            }
            
        }
        
        return ret;
    }
};