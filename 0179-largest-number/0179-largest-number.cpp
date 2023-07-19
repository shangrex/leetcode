bool comp(int a, int b){
    string s_a = to_string(a);
    string s_b = to_string(b);
    string ab = s_a+s_b;
    string ba = s_b+s_a;
    for(int i = 0 ; i < ab.length(); i++){
        if(ab[i] > ba[i])return true;
        else if(ab[i] < ba[i])return false;
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string rst = "";
        for(int i = 0; i < nums.size(); i++){
            rst += to_string(nums[i]);
        }
        
        if(rst[0] == '0' && rst.length() > 1)return "0";
        
        return rst;
    }
};