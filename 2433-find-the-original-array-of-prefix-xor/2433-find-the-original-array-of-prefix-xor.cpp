class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
      // 5^x = 2
      // x = 2^5    
      // 0 = 5^7^y, y = 5^7^0

      vector<int> ret;
      int prefix = pref[0];
      ret.push_back(prefix);
      for(int i = 1; i < pref.size(); i++){
        int pushNum = prefix ^ pref[i];
        ret.push_back(pushNum);
        prefix ^= pushNum;
      }
      return ret;
    }
};