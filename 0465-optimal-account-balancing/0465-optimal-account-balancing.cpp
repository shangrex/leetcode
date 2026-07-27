class Solution {
public:
    vector<long> debt;

    int dfs(int pos){
        if(pos == debt.size())  return 0;
        if(debt[pos] == 0) return dfs(pos+1);
        
        int ret = INT_MAX;
        for(int i = pos+1; i < debt.size(); i++){
            if(debt[i] * debt[pos] < 0){
                debt[i] += debt[pos];
                //cout << pos << " " << debt[pos] << " " << debt[i] << endl;
                ret = min(ret, 1 + dfs(pos+1));
                debt[i] -= debt[pos];
            }
        }
        return ret;
    }
    int minTransfers(vector<vector<int>>& transactions) {
        /*
        0     1  2
        -10   10  0
        -5   10  -5

        0.    5. -5
        5  -10
        */
        unordered_map<long, long> balance;
        for(int i = 0; i < transactions.size(); i++){
            balance[transactions[i][1]] += transactions[i][2];
            balance[transactions[i][0]] -= transactions[i][2];
        }

        for(auto &i : balance){
            if(i.second != 0)
                debt.push_back(i.second);
        }
        return dfs(0);
    }
};