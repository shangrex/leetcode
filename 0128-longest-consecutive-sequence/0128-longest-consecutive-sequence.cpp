class Solution {
public:
/*
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        int ret = 0;
        for(auto i : st){
            if(st.count(i-1)==0){
                int curNum = i;
                int streak = 1;
                while(st.count(curNum+1) > 0){
                    curNum += 1;
                    streak++;
                }
                ret = max(ret, streak);
            }
            
        }
        return ret;
*/

    set<int>s;


    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        for(auto &n : nums){
            s.insert(n);
        }

        for(auto i: s){
            if(!s.count(i-1)){
                int numStrike = 1;
                int numTrack = i;
                while(s.count(numTrack+1) > 0){
                    numStrike++;
                    numTrack++;
                }
                ret = max(ret, numStrike);
            }
        }
        return ret;
    }
};