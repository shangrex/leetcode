class Solution {
public:
    void dfs(string para, vector<string>&rst, int& n, int l){
        if(para.length() > n*2)return;
        else if(para.length() == n*2 && l == 0){
            rst.push_back(para);
        }
        
        dfs(para+"(", rst, n, l+1);
        
        if(l > 0){
            dfs(para+")", rst, n, l-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>rst;
        dfs("", rst, n, 0);
        return rst;
    }
};