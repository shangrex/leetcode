class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>> &image, int sr, int sc, int org_color, int color, vector<vector<bool>>&visit){
        int m = image.size();
        int n = image[0].size();
        if(sr < 0 || sc < 0 || sr >= m || sc >= n) { return ;}
        visit[sr][sc] = true;
        if(image[sr][sc] == org_color) {
            image[sr][sc] = color;
        }
        if(sr+1 < m && image[sr+1][sc] == org_color && visit[sr+1][sc] == false)        
            dfs(image, sr+1, sc, org_color, color, visit);
        if(sr-1 >= 0 && image[sr-1][sc] == org_color && visit[sr-1][sc] == false)        
            dfs(image, sr-1, sc, org_color, color, visit);
        if(sc+1 < n && image[sr][sc+1] == org_color && visit[sr][sc+1] == false)        
            dfs(image, sr, sc+1, org_color, color, visit);
        if(sc-1 >= 0 && image[sr][sc-1] == org_color && visit[sr][sc-1] == false)        
            dfs(image, sr, sc-1, org_color, color, visit);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visit(image.size(), vector<bool>(image[0].size(), false));
        dfs(image, sr, sc, image[sr][sc], color, visit);
        return image;
    }
};