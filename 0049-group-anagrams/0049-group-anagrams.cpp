class Solution {
public:
    /*
    approach 1: use orederd map(map) to compare each word,
    approach 2: use sort to compare each word
        the sort have an optimize method that use transform map to string so that it can use counting sort
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> rst;
        map<map<char,int>, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            map<char,int>tmp;
            for(int j = 0; j < strs[i].length(); j++){
                tmp[strs[i][j]] += 1;
            }
            mp[tmp].push_back(strs[i]);
        }
        
        for(auto i: mp){
            vector<string>tmp;
            for(auto j : i.second){
                tmp.push_back(j);
            }
            rst.push_back(tmp);
        }
        return rst;
    }
};