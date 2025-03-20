class Solution {
public:
    int tot = 0;
    vector<int>prefix;
    Solution(vector<int>& w) {
        for(auto i : w){
            tot += i;
            prefix.push_back(tot);
        }
    }
    
    int pickIndex() {
        int select = rand()%tot;
        cout << select << endl;
        for(int i = 0; i < prefix.size(); i++){
            if(select < prefix[i]) return i;
        }
        return prefix.size()-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */