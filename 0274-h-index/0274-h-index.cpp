class Solution {
public:
    /*
    Approach 1. after sorting, the key(index) of the citations can be seen as
    the number of larget rst
    so to get the number of citations which is larget than rst is citations[n_c - rst]
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int rst = 1;
        int n_c = citations.size();
        
        while(rst <= n_c && citations[n_c - rst] >= rst){
            rst++;
        }
        
        return rst-1;
    }
    
    Approach 2. use couting to record the number of citations which is larget than rst
    */
    int hIndex(vector<int>& citations) {
        int rst = 1;
        int n_c = citations.size();
        vector<int>count(10100, 0);
        
        for(int i = 0; i < citations.size(); i++){
            count[min(n_c, citations[i])] ++;
        }
        
        int cnt = 0;
        for(int i = n_c; i >=0; i--){
            cnt += count[i];
            if(cnt >= i){rst = i;break;}
        }
        
        return rst;
    }
};