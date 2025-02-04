class Solution {
public:
    /*
    Monothonic stack non continuslly subsequence

    stack<int> inc_st, dec_st;
        int inc_len = 0, dec_len = 0;
        for(auto num : nums){
            if(inc_st.empty()){
                inc_st.push(num);
                inc_len = 1;
                continue;
            }
            if(inc_st.top() < num){
                inc_st.push(num);
                inc_len = max(inc_len, (int)inc_st.size());
            }
            else {
                while(!inc_st.empty() && inc_st.top() >= num){
                    inc_st.pop();
                }
                inc_st.push(num);
            }
        }


        for(auto num : nums){
            if(dec_st.empty()){
                dec_st.push(num);
                dec_len = 1;
                continue;
            }
            if(dec_st.top() > num){
                dec_st.push(num);
                dec_len = max(dec_len, (int)dec_st.size());
            }
            else {
                while(!dec_st.empty() && dec_st.top() <= num){
                    dec_st.pop();
                }
                dec_st.push(num);
            }
        }
        return max(inc_len, dec_len);



    subarray means continusous array
    */
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc_len = 1, dec_len = 1, ans_inc_len = 1, ans_dec_len = 1;
        int inc_tmp = nums[0], dec_tmp = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > inc_tmp){
                inc_len++;
            }
            else {
                inc_len = 1;
            }
            ans_inc_len = max(ans_inc_len, inc_len);
            inc_tmp = nums[i];
        }

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < dec_tmp){
                dec_len++;
            }
            else {
                dec_len = 1;
            }
            ans_dec_len = max(ans_dec_len, dec_len);
            dec_tmp = nums[i];
        }
        return max(ans_dec_len, ans_inc_len);
    }
};