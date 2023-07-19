class Solution {
public:
    /*
    approach 1: bruce force
    time complexity N^2
       int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int j = 0; j < gas.size(); j++){
            bool check = true;
            int tmp_gas = gas[j];
            for(int i = 0; i < gas.size(); i++){
                if(tmp_gas - cost[(j+i)%gas.size()] < 0){
                    check = false;
                }
                tmp_gas = tmp_gas - cost[(j+i)%gas.size()] + gas[(j+i+1)%gas.size()];
            }
            if(check)return j;
        }
        return -1;
    } 
    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int j = 0; j < gas.size(); j++){
            bool check = true;
            int tmp_gas = gas[j];
            for(int i = 0; i < gas.size(); i++){
                if(tmp_gas - cost[(j+i)%gas.size()] < 0){
                    check = false;
                    j = j+i;
                    break;
                }
                tmp_gas = tmp_gas - cost[(j+i)%gas.size()] + gas[(j+i+1)%gas.size()];
            }
            if(check)return j;
        }
        return -1;
    }
};