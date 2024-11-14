class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>> &image, int sr, int sc, int org_color, int color){
        int m = image.size();
        int n = image[0].size();

        if(image[sr][sc] == org_color) {
            image[sr][sc] = color;
            if(sr+1 < m && image[sr+1][sc] == org_color)        
                dfs(image, sr+1, sc, org_color, color);
            if(sr-1 >= 0 && image[sr-1][sc] == org_color)        
                dfs(image, sr-1, sc, org_color, color);
            if(sc+1 < n && image[sr][sc+1] == org_color)        
                dfs(image, sr, sc+1, org_color, color);
            if(sc-1 >= 0 && image[sr][sc-1] == org_color)        
                dfs(image, sr, sc-1, org_color, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color != image[sr][sc])
            dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};