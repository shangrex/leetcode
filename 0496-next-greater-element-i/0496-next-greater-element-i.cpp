class Solution {
public:
    /*
    Monotonic stack
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        stack<int>st;
        st.push(nums2[0]);
        vector<int>rst;
        for(int i = 1; i < nums2.size(); i++){

            while(!st.empty() && st.top() <= nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for(auto num1 : nums1){
            if(mp.find(num1) != mp.end()){
                rst.push_back(mp[num1]);
            }
            else rst.push_back(-1);
        }
        return rst;
    }
};