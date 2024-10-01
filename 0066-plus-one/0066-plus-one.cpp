class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }
            else {
                digits[i] += carry;
                carry = 0;
                break;
            }
        }
        if(carry != 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};