class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int rst = 1;
        int n_c = citations.size();
        
        while(rst <= n_c && citations[n_c - rst] >= rst){
            rst++;
        }
        
        
        return rst-1;
    }
};