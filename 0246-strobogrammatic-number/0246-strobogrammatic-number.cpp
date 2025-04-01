class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char>mp {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'9', '6'}, {'8', '8'}};

        int left = 0, right = num.length()-1;
  
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