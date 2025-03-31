class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char>mp {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'9', '6'}, {'8', '8'}};

        int left = 0, right = num.length()-1;
        if(num.length() == 1){
            if(num[0] == '1' || num[0] == '0' || num[0] == '8') return true;
            else return false;
        } 

        while(left <= right){
            if(mp.find(num[left]) == mp.end()){
                return false;
            }
            else if(mp[num[left]] != num[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};