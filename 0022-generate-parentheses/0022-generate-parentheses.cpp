class Solution {
public:
    void helper(vector<string>&output, string s, int n, int count_left, int count_right){
        if(count_left == count_right && count_right == n){
            output.push_back(s);
            return;
        }
        if(count_left > n || count_right > n)return;
        if(count_left - count_right > 0){
            // add left bracket
            helper(output, s+"(" , n, count_left+1, count_right);
            // add right bracket
            helper(output, s+")" , n, count_left, count_right+1);
        }
        else {
            helper(output, s+"(" , n, count_left+1, count_right);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        helper(output, "", n, 0, 0);
        return output;
    }
};