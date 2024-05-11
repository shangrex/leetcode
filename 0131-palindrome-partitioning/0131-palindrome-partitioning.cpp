class Solution {
public:
    
    bool valid(string s){
        int left = 0, right = s.length()-1;
        while(left <= right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    vector<vector<string>>rst;
    void backtrack(int index, string &s, vector<string>&pool){
        if(index == s.length()){
            rst.push_back(pool);
            return;
        }
        
        for(int i = index; i < s.length(); i++){
            string s_tmp = s.substr(index, i-index+1);
            if(valid(s_tmp)){
                pool.push_back(s_tmp);
                backtrack(i+1, s, pool);
                pool.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>pool;
        for(int i = 0; i < s.length(); i++){
            string s_tmp = s.substr(0, i+1);
            if(valid(s_tmp)){
                pool.push_back(s_tmp);
                backtrack(i+1, s, pool);
                pool.pop_back();
            } 
        }
        return rst;
    }
};