class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int rst = 0;
        int total_gas = 0;
        int cur_gas = 0;
        for(int i = 0; i < n; i++){
            total_gas += (gas[i] - cost[i]);
            cur_gas += (gas[i] - cost[i]);
            if(cur_gas < 0){
                cur_gas = 0;
                rst = (i+1)%n;
            }
        }
        if(total_gas < 0){
            return -1;
        }

        return rst;
    }
};