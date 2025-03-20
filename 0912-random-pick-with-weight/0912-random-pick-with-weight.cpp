class Solution {
public:
    /*
    Appoach 1. prefix sum with linear search

    Approac 2. prefix sum with binary search
    */
    int tot = 0;
    vector<int>prefix;
    Solution(vector<int>& w) {
        for(auto i : w){
            tot += i;
            prefix.push_back(tot);
        }
    }
    
    int pickIndex() {
        // int select = rand()%tot;
        // for(int i = 0; i < prefix.size(); i++){
        //     if(select < prefix[i]) return i;
        // }
        // return prefix.size()-1;


        int select = rand()%tot;
        int left = 0, right = prefix.size()-1;
        // find the biggest smaller index
        // 1 2 3
        // if select is 2, should select index 2
        // 3
        // if select is 5
        // 1 3 6
        // 0 2 5
        // l.  r
        //.    l 
        //.    l
        while(left < right){
            int mid = (left+right)/2;
            if(prefix[mid] > select){
                right = mid;
            }
            else left = mid+1;
        }

        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */