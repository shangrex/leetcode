class Solution {
public:
    /*
    Hint: divide & conquer
    notice that top-left -> bottom-left -> top-left -> top-right
    design border for its square.
    the ending condition
    the 
    */
    int val = 0;
    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        int rowStart = 0, rowEnd = size, colStart = 0, colEnd = size;
        vector<vector<int>> ret(size, vector<int>(size, 0));
        solve(ret, rowStart, rowEnd, colStart, colEnd);

        return ret;
    }

private:
    void solve(vector<vector<int>> &ret, int rowStart, int rowEnd, int colStart, int colEnd){
        int size = rowEnd - rowStart;
        if(size == 1){
            ret[rowStart][colStart] = val++;
            return ;
        }

        int rowMid = rowStart + (rowEnd - rowStart)/2;
        int colMid = colStart + (colEnd - colStart)/2;
        solve(ret, rowStart, rowMid, colMid, colEnd); // top-right
        solve(ret, rowMid, rowEnd, colMid, colEnd); // bottom-right
        solve(ret, rowMid, rowEnd, colStart, colMid); // bottom-left
        solve(ret, rowStart, rowMid, colStart, colMid); // top-left

    }

};