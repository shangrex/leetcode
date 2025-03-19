class Solution {
public:
    /*
    Hint: Edge case: strs.size() == 1
    */
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)return strs[0];
        int ret = 0;

        while(true){
            bool flag = true;
            for(int i = 0; i < strs.size()-1; i++){
                if(ret >= strs[i].length() || ret >= strs[i+1].length()) {
                    flag = false;
                    break;
                }
                if(strs[i][ret] != strs[i+1][ret]){
                    flag = false;
                    break;
                }
            }
            if(!flag)break;
            else ret++;
        }
  

        return strs[0].substr(0, ret);
    }
};